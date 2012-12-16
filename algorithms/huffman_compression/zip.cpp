#include <zip.h>

#include <iostream>
#include <set>

using namespace std;

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

class TBitBuf {
private:
    //TBuf Buf;
    //i64 BitsCount;
    vector<bool> Bits;
public:
    TBitBuf() {
    }

    /*
    void WriteByte(unsigned char symbol) {
        const long long bytesCount = BitsCount >> 3;
        const long long freeBits = BitsCount - (bytesCount << 3);
        if (freeBits == 8) {
            Buf.push_back(symbol);
        } else {
            //
        }
    }
    */

    void WriteByte(unsigned char symbol) {
        const int sym = symbol;
        for (int i = 0; i < 8; ++i) {
            const int mask = 1 << i;
            const bool bit = sym & mask;
            Bits.push_back(bit);
        }
    }

    void WriteBit(bool bit) {
        Bits.push_back(bit);
    }

    void Clear() {
        Bits.clear();
    }

    const vector<bool> &GetBits() const {
        return Bits;
    }
};

/*
Zip:
    file ->
    bytes in TBuf ->
    encoded bits in TBitBuf ->
    encoded bits in TBuf with bit-length as prefix ->
    file

Unzip:
    file ->
    bytes in TBuf ->
    decoded
*/

static void MemBytesToBitBuf(const TBuf &buf, TBitBuf &bitBuf) {
    for (TBuf::const_iterator iter = buf.begin(), end = buf.end(); iter != end; ++iter)
        bitBuf.WriteByte(*iter);
}

static void MemBitsToBitBuf(const TBuf &buf, TBitBuf &bitBuf) {
    //
}


void Zip(const TBuf &in, TBuf &out) {
    TSymbol2Freq symbol2freq(DIC_SIZE);
    CalcAlphabetStats(in, symbol2freq);
    TCodeTree codeTree(symbol2freq);
    cout << "Mean symbol length: " << codeTree.CalcMeanSymbolLenth() << endl;
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
