#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <exception>

#include <boost/shared_ptr.hpp>

using namespace std;

long long GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

class TException : public std::exception {
private:
    string Descr;
public:
    TException(const string &descr)
        : Descr(descr) {
    }

    virtual ~TException() throw() {
    }

    virtual const char *what() throw() {
        return Descr.c_str();
    }
};

static void GenerateInputFile(const char *fname, int size) {
    FILE *pFile = fopen(fname, "wb");
    for (int i = 0; i < size; ++i) {
        const int num = rand();
        if (!fwrite(&i, sizeof(int), 1, pFile))
            throw TException("Failed writing number to file!");
    }
}

class TChunk {
private:
    const char *InputFileName;
    const char *TempFileName;
    int Offset;
    int MaxSize;
    int Size;
    string TmpFileName;
    FILE *TmpFile;
    int CurrentValue;
    bool Valid;
private:
    void MakeTmpFileName(int offset) {
        char buf[256];
        sprintf(buf, "tmp_%04d", offset / MaxSize);
        TmpFileName = buf;
    }
public:
    TChunk(const char *inputFileName, int offset, int maxSize)
        : InputFileName(inputFileName)
        , Offset(offset)
        , MaxSize(maxSize)
        , Valid(false) {
        MakeTmpFileName(offset);
    }

    ~TChunk() {
        fclose(TmpFile);
    }

    void Init() {
        // reading input
        FILE *ifile = fopen(InputFileName, "rb");
        if (!ifile)
            throw TException("Couldn't open input file in TChunk::Init!");

        vector<int> v(MaxSize);
        if (fseek(ifile, Offset * sizeof(int), SEEK_SET))
            throw TException("Seek failed!");
        Size = fread(&v[0], sizeof(int), MaxSize, ifile);
        v.resize(Size);
        std::sort(v.begin(), v.end());
        fclose(ifile);

        // sorting chunk
        FILE *tfile = fopen(TmpFileName.c_str(), "wb");
        if (!tfile)
            throw TException("Couldn't open temp file in TChunk::Init!");

        fwrite(&v[0], sizeof(int), Size, tfile);
        fclose(tfile);

        //
        TmpFile = fopen(TmpFileName.c_str(), "rb");
        if (!TmpFile)
            throw TException("Couldn't open temp file!");

        if (fseek(TmpFile, Offset * sizeof(int), SEEK_SET))
            throw TException("Seek (2) failed!");

        Valid = true;
        Next();
    }

    bool IsValid() const {
        return Valid;
    }

    void Next() {
        if (!Valid)
            throw TException("Error! Trying to call next for invalid chunk!");

        const int cnt = fread(&CurrentValue, sizeof(int), 1, TmpFile);
        if (!cnt)
            Valid = false;
    }

    int GetCurrentValue() const {
        return CurrentValue;
    }
};

struct TChunkComparator {
    bool opeartor()(const boost::shared_ptr<TChunk> &lhs, const boost:shared_ptr<TChunk> &rhs) const {
        return lhs->GetCurrentValue() < rhs->GetCurrentValue();
    }
};

static void DistributedSort(const char *inputFileName, const char *outputFileName, int size, int maxChunkSize) {
    cout << "Creating chunks ..." << endl;
    vector< boost::shared_ptr<TChunk> > chunks;
    for (int offset = 0; offset < size; offset += maxChunkSize) {
        boost::shared_ptr<TChunk> pc(new TChunk(inputFileName, offset, maxChunkSize));
        chunks.push_back(pc);
    }

    const int chunksCnt = chunks.size();
    cout << "Total number of chunks: " << chunksCnt << endl;
    cout << "Sorting chunks ..." << endl;
    int sortedChunks = 0;
    for (vector< boost::shared_ptr<TChunk> >::const_iterator iter = chunks.begin(), end = chunks.end(); iter != end; ++iter, ++sortedChunks) {
        boost::shared_ptr<TChunk> pc = *iter;
        cout << "sorting chunk: " << sortedChunks << " (total: " << chunksCnt << ")" << endl;
        pc->Init();
    }

    FILE *ofile = fopen(outputFileName, "wb");
    if (!ofile)
        throw TException("Couldn't open output file!");

    //
}

static void Test() {
    const char inputFileName[] = "input.bin";
    const char outputFileName[] = "output.bin";
    const int size = 256 * 1024 * 1024;
    //const int maxChunkSize = 25 * 1000 * 1000;
    const int maxChunkSize = 32 * 1024 * 1024;
    //cout << "Generating input file..." << endl;
    //GenerateInputFile(inputFileName, size);
    cout << "Sorting..." << endl;
    DistributedSort(inputFileName, outputFileName, size, maxChunkSize);
    cout << "Done" << endl;
}

int main() {
    try {
        Test();
    } catch (const std::exception &xcp) {
        cout << "An std::exception occured: " << xcp.what() << endl;
    }
    return 0;
}
