#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

    virtual const char *what() const throw() {
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
        sprintf(buf, "tmp_%04d.bin", offset / MaxSize);
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
        Size = 32 * 1024 * 1024;

        //
        TmpFile = fopen(TmpFileName.c_str(), "rb");
        if (!TmpFile)
            throw TException("Couldn't open temp file!");

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
        if (cnt != 1)
            Valid = false;
    }

    int GetCurrentValue() const {
        return CurrentValue;
    }

    const string &GetName() const {
        return TmpFileName;
    }
};

typedef vector< boost::shared_ptr<TChunk> > TPChunks;

struct TChunkComparator {
    bool operator()(const boost::shared_ptr<TChunk> &lhs, const boost::shared_ptr<TChunk> &rhs) const {
        return lhs->GetCurrentValue() < rhs->GetCurrentValue();
    }
};

static void DistributedSort(const char *inputFileName, const char *outputFileName, int size, int maxChunkSize) {
    const long long start = GetTickCount();

    cout << "Creating chunks ..." << endl;
    TPChunks chunks;
    for (int offset = 0; offset < size; offset += maxChunkSize) {
        boost::shared_ptr<TChunk> pc(new TChunk(inputFileName, offset, maxChunkSize));
        chunks.push_back(pc);
    }

    const int chunksCnt = chunks.size();
    cout << "Total number of chunks: " << chunksCnt << endl;
    cout << "Sorting chunks ..." << endl;
    int sortedChunks = 0;
    for (TPChunks::const_iterator iter = chunks.begin(), end = chunks.end(); iter != end; ++iter, ++sortedChunks) {
        boost::shared_ptr<TChunk> pc = *iter;
        cout << "sorting chunk: " << sortedChunks << " (total: " << chunksCnt << ")" << endl;
        pc->Init();
    }

    cout << "RUNNING TIME = " << (GetTickCount() - start) << endl;

    FILE *ofile = fopen(outputFileName, "wb");
    if (!ofile)
        throw TException("Couldn't open output file!");

    cout << "Initializing queue..." << endl;
    typedef priority_queue< boost::shared_ptr<TChunk>, TPChunks, TChunkComparator > TQueue;
    TQueue q;
    for (TPChunks::const_iterator iter = chunks.begin(), end = chunks.end(); iter != end; ++iter) {
        cout << (*iter)->GetName() << endl;
        if ((*iter)->IsValid() == false)
            throw TException("Invalid chunk! " + (*iter)->GetName());
        q.push(*iter);
    }

    cout << "RUNNING TIME = " << (GetTickCount() - start) << endl;

    cout << "Merging..." << endl;
    for (int i = 0; !q.empty(); ++i) {
        boost::shared_ptr<TChunk> pchunk = q.top();
        q.pop();
        const int val = pchunk->GetCurrentValue();
        const int cnt = fwrite(&val, sizeof(int), 1, ofile);
        if (cnt != 1)
            throw TException("Failed writing num to output file!");

        pchunk->Next();
        if (pchunk->IsValid())
            q.push(pchunk);

        if (i % 1000000 == 0)
            cout << "merged: " << i << " of " << size << endl;
    }

    fclose(ofile);
    cout << "RUNNING TIME = " << (GetTickCount() - start) << endl;
}

static void Test() {
    const char inputFileName[] = "input.bin";
    const char outputFileName[] = "output.bin";

    const int size = 1024 * 1024 * 1024;
    const int maxChunkSize = 16 * 1024 * 1024;

    cout << "Generating input file..." << endl;
    GenerateInputFile(inputFileName, size);

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
