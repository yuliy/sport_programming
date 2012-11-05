#pragma once

#include <exception>
#include <string>
#include <vector>

namespace ystd {
    class TZipException : public std::exception {
    private:
        std::string Descr;
    public:
        TZipException(const std::string &descr);
        virtual ~TZipException() throw();
        virtual const char *what() const throw();
    };

    void Zip(std::string inFileName, std::vector<unsigned char> &out);
    void Zip(std::string inFileName, std::string outFileName);

    void Unzip(std::string inFileName, std::vector<unsigned char> &out);
    void Unzip(std::string inFileName, std::string outFileName);
} // namespace ystd
