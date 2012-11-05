#include <zip.h>

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

void Zip(std::string inFileName, std::vector<char> &out) {
    throw TZipException("Not implemented!");
}

void Zip(std::string inFileName, std::string outFileName) {
    throw TZipException("Not implemented!");
}

void Unzip(std::string inFileName, std::vector<char> &out) {
    throw TZipException("Not implemented!");
}

void Unzip(std::string inFileName, std::string outFileName) {
    throw TZipException("Not implemented!");
}

} // namespace ystd
