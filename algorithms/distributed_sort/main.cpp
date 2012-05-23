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

static void Test() {
    const char inputFileName[] = "input.bin"; 
    cout << "Generating input file..." << endl;
    GenerateInputFile(inputFileName, 256 * 1024 * 1024);
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
