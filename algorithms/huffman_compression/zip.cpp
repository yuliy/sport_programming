#include <zip.h>

#include <cstdio>
#include <iostream>

using namespace std;

namespace ystd {

// TZipException

TZipException::TZipException(const string &descr)
    : Descr(descr) {
}

TZipException::~TZipException() throw() {
}

const char *TZipException::what() const throw() {
    return Descr.c_str();
}

//

const int DIC_SIZE = 256;

void Zip(const string &inFileName, vector<unsigned char> &out) {
    FILE *file = fopen(inFileName.c_str(), "rb");
    if (!file)
        throw TZipException("Couldn't open file " + inFileName);

    unsigned char c;
    vector<unsigned char> data;
    vector<int> freqs(DIC_SIZE);
    while (fread(&c, sizeof(unsigned char), 1, file) == 1) {
        ++freqs[(int)c];
        data.push_back(c);
    }
    cout << "Frequencies:" << endl;
    for (int i = 0; i < DIC_SIZE; ++i) {
        cout << i << " (" << (char)i << "): " << freqs[i] << endl;
    }

    cout << "File size is: " << data.size() << " bytes" << endl;
    fclose(file);
}

static void WriteToFile(const string &fileName, const vector<unsigned char> &data) {
    FILE *file = fopen(fileName.c_str(), "wb");
    if (!file)
        throw TZipException("Couldn't open file " + fileName);

    if (!fwrite(&data[0], sizeof(unsigned char), data.size(), file))
        throw TZipException("Failed writing data to file fileName=" + fileName);
}

void Zip(const string &inFileName, const string &outFileName) {
    vector<unsigned char> data;
    Zip(inFileName, data);
    WriteToFile(outFileName, data);
}

void Unzip(const string &inFileName, vector<unsigned char> &out) {
    throw TZipException("Not implemented!");
}

void Unzip(const string &inFileName, const string &outFileName) {
    throw TZipException("Not implemented!");
}

} // namespace ystd
