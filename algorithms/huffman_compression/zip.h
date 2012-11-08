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

    void Zip(const std::string &inFileName, std::vector<unsigned char> &out);
    void Zip(const std::string &inFileName, const std::string &outFileName);

    void Unzip(const std::string &inFileName, std::vector<unsigned char> &out);
    void Unzip(const std::string &inFileName, const std::string &outFileName);
} // namespace ystd
