#pragma once

#include <cstdio>
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

    typedef std::vector<unsigned char> TBuf;

    /*
    class TFileReader {
    private:
        FILE *File;
    public:
        TFileReader(const std::string &path);
        ~TFileReader();
        bool ReadByte(char &ch);
        bool ReadBit(bool &bit);
    };
    */

    void ReadFileToMem(const std::string &inFileName, TBuf &buf);
    void WriteMemToFile(const std::string &outFileName, const TBuf &buf);

    void Zip(const TBuf &in, TBuf &out);
    void Unzip(const TBuf &in, TBuf &out);

    //void Zip(const std::string &inFileName, std::vector<unsigned char> &out);
    //void Zip(const std::string &inFileName, const std::string &outFileName);

    //void Unzip(const std::string &inFileName, std::vector<unsigned char> &out);
    //void Unzip(const std::string &inFileName, const std::string &outFileName);
} // namespace ystd
