#include <zip.h>

#include <iostream>
#include <set>

#include "tools.h"

using namespace std;
using namespace ystd;

namespace ystd {

/**
  * TZipException
  */

TZipException::TZipException(const string &descr)
    : Descr(descr) {
}

TZipException::~TZipException() throw() {
}

const char *TZipException::what() const throw() {
    return Descr.c_str();
}

/**
  * TFileReader
  */

/*
TFileReader::TFileReader(const std::string &path) {
    File = fopen(path.c_str(), "rb");
    if (!File)
        throw TZipException("Couldn't open file " + path);
}

TFileReader::~TFileReader() {
    fclose(File);
}

bool TFileReader::ReadByte(char &ch) {

}

bool TFileReader::ReadBit(bool &bit) {

}
*/

void ReadFileToMem(const std::string &inFileName, TBuf &buf) {
    FILE *file = fopen(inFileName.c_str(), "rb");
    if (!file)
        throw TZipException("Couldn't open file " + inFileName);

    unsigned char c;
    while (1 == fread(&c, sizeof(unsigned char), 1, file))
        buf.push_back(c);

    fclose(file);
}

void WriteMemToFile(const std::string &outFileName, const TBuf &buf) {
    FILE *file = fopen(outFileName.c_str(), "wb");
    if (!file)
        throw TZipException("Couldn't open file " + outFileName);

    if (buf.size() != fwrite(&buf[0], sizeof(unsigned char), buf.size(), file))
        throw TZipException("Failed writing data to file fileName=" + outFileName);

    fclose(file);
}

const int DIC_SIZE = 256;

typedef vector<double> TSymbol2Freq;

static void CalcAlphabetStats(const TBuf &buf, TSymbol2Freq &symbol2freq) {
    for (TBuf::const_iterator iter = buf.begin(), end = buf.end(); iter != end; ++iter) {
        const int symbol = (int)(*iter);
        ++symbol2freq[symbol];
    }

    for (int i = 0; i < DIC_SIZE; ++i)
        symbol2freq[i] /= buf.size();
}

/*
static void SerializeAlphabetStats(const TSymbol2Freq &symbol2freq, TBitBuf &bitBuf) {
    for (int i = 0; i < DIC_SIZE; ++i) {
        bitBuf.
    }
}

static void DeserializeAlphabetStats(const TBuf &buf, TSymbol2Freq &symbol2freq) {

}
*/

struct TNode {
    TNode *Parent;
    TNode *Left;
    TNode *Right;
    unsigned char Symbol;
    double Probability;

    TNode()
        : Parent(0)
        , Left(0)
        , Right(0)
        , Symbol(0)
        , Probability(0.0) {
    }

    TNode(unsigned char symbol, double probability)
        : Parent(0)
        , Left(0)
        , Right(0)
        , Symbol(symbol)
        , Probability(probability) {
    }
};

typedef vector<TNode*> TPNodes;

struct TNodesComparator {
    bool operator()(const TNode *lhs, const TNode *rhs) const {
        if (lhs->Probability != rhs->Probability)
            return lhs->Probability < rhs->Probability;
        return lhs->Symbol < rhs->Symbol;
    }
};

class TCodeTree {
private:
    TPNodes SymbolNodes;
    TPNodes InternalNodes;
    TNode *Root;
private:
    TCodeTree();
    TCodeTree(const TCodeTree&);
    TCodeTree& operator=(const TCodeTree&);
private:
    int CalcSymbolLength(TNode *node) {
        int res = 0;
        for (; node && node->Parent; node = node->Parent)
            ++res;
        return res;
    }
public:
    TCodeTree(const TSymbol2Freq &symbol2freq)
        : Root(0) {
        typedef set<TNode*, TNodesComparator> TMetaSymbols;
        typedef TMetaSymbols::iterator TMSIter;
        TMetaSymbols metaSymbols;
        for (int i = 0; i < DIC_SIZE; ++i) {
            TNode *pn = new TNode((unsigned char)i, symbol2freq[i]);
            SymbolNodes.push_back(pn);
            metaSymbols.insert(pn);
        }

        while (metaSymbols.size() > 1) {
            TMSIter iter1 = metaSymbols.begin();
            TNode *node1 = *iter1;
            metaSymbols.erase(iter1);

            TMSIter iter2 = metaSymbols.begin();
            TNode *node2 = *iter2;
            metaSymbols.erase(iter2);

            TNode *metaNode = new TNode();
            metaNode->Left = node1;
            metaNode->Right = node2;
            metaNode->Probability = node1->Probability + node2->Probability;

            node1->Parent = metaNode;
            node2->Parent = metaNode;

            InternalNodes.push_back(metaNode);
            metaSymbols.insert(metaNode);
        }

        Root = *(metaSymbols.begin());
    }

    ~TCodeTree() {
        for (TPNodes::iterator iter = SymbolNodes.begin(); iter != SymbolNodes.end(); ++iter)
            delete *iter;
        for (TPNodes::iterator iter = InternalNodes.begin(); iter != InternalNodes.end(); ++iter)
            delete *iter;
    }

    void Encode(unsigned char symbol, TBitBuf &out) const {
        TNode *node = SymbolNodes[(int)symbol];
        for (; node && node->Parent; node = node->Parent) {
        /*
            const TNode *parent = node->Parent;
            if (node == parent->Left) {
                out.push_back(false);
            } else (node == parent->Right) {
                out.push_back(true);
            } else
                throw TZipException("Error encoding symbol!");
                */
        }
    }

    double CalcMeanSymbolLenth() {
        double res = 0.0;
        for (TPNodes::iterator iter = SymbolNodes.begin(); iter != SymbolNodes.end(); ++iter) {
            TNode *node = *iter;
            const int len = CalcSymbolLength(node);
            res += (node->Probability * len);
        }
        return res;
    }
};

/*
Zip:
    file ->
    bytes in TBuf ->
    encoded bits in TBitBuf ->
    dictionary + data length in bits + encoded data in TBuf ->
    file

Unzip:
    file ->
    bytes in TBuf ->
    dictionary + encoded bits in TBitBuf ->
    decoded bytes in TBuf
*/

static void Encode(const TBuf &in, const TCodeTree &ct, TBitBuf &out) {
    for (TBuf::const_iterator iter = in.begin(), end = in.end(); iter != end; ++iter) {
        const unsigned char symbol = *iter;
        ct.Encode(symbol, out);
    }
}

void Zip(const TBuf &in, TBuf &out) {
    TSymbol2Freq symbol2freq(DIC_SIZE);
    CalcAlphabetStats(in, symbol2freq);
    TCodeTree codeTree(symbol2freq);
    cout << "Mean symbol length: " << codeTree.CalcMeanSymbolLenth() << endl;

    TBitBuf bitBuf;
    Encode(in, codeTree, bitBuf);
}

void Unzip(const TBuf &in, TBuf &out) {

}

/*
void Unzip(const string &inFileName, vector<unsigned char> &out) {
    throw TZipException("Not implemented!");
}

void Unzip(const string &inFileName, const string &outFileName) {
    throw TZipException("Not implemented!");
}
*/

} // namespace ystd
