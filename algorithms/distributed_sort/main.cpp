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
public:
    TChunk(const char *inputFileName, int offset, int maxSize)
        : InputFileName(inputFileName)
        , Offset(offset)
        , MaxSize(maxSize) {
    }

    void Init() {

    }
};

static void DistributedSort(const char *inputFileName, const char *outputFileName, int size, int maxChunkSize) {
    FILE *ifile = fopen(inputFileName, "rb");
    if (!ifile)
        throw TException("Couldn't open input file!");

    cout << "Creating chunks ..." << endl;
    vector< boost::shared_ptr<TChunk> > chunks;
    for (int offset = 0; offset < size; offset += maxChunkSize) {
        boost::shared_ptr<TChunk> pc(new TChunk(inputFileName, offset, maxChunkSize));
        //pc->Init();
        chunks.push_back(pc);
    }

    const int chunksCnt = chunks.size();
    cout << "Total number of chunks: " << chunksCnt << endl;
    cout << "Sorting chunks ..." << endl;
    int sortedChunks = 0;
    for (vector< boost::shared_ptr<TChunk> >::const_iterator iter = chunks.begin(), end = chunks.end(); iter != end; ++iter, ++sortedChunks) {
        boost::shared_ptr<TChunk> pc = *iter;
        cout << "sorting chunks: " << sortedChunks << endl;
        pc->Init();
    }
}

static void Test() {
    const char inputFileName[] = "input.bin";
    const char outputFileName[] = "output.bin";
    const int size = 256 * 1024 * 1024;
    const int maxChunkSize = 1000 * 1000;
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
