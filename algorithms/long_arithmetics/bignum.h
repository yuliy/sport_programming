#pragma once

#include <exception>
#include <string>
#include <vector>
#include <iostream>

namespace ystd {
    class TBigIntException : public std::exception {
    private:
        std::string Desc;
    private:
        TBigIntException();
    public:
        explicit TBigIntException(const char *desc);
        ~TBigIntException() throw();
        const char *what() const throw();
    };

    class TBigInt {
    private:
        typedef std::vector<int> TDigits;
        typedef TDigits::iterator TIter;
        typedef TDigits::const_iterator TCIter;
        typedef TDigits::reverse_iterator TRIter;
        typedef TDigits::const_reverse_iterator TCRIter;
    private:
        TDigits Digits;
        static const int BASE = 10000;
        static const int BASE_DIGITS_CNT = 4;
    private:
        void Normalize();
        static void Divide(const TBigInt &a, int b, TBigInt &res, int &remainder);
        static void Divide(const TBigInt &a, TBigInt b, TBigInt &res, TBigInt &remainder);
    public:
        TBigInt();
        TBigInt(const TBigInt &other);
        TBigInt(int num);
        TBigInt(long long num);
        explicit TBigInt(const char *str);
        explicit TBigInt(const std::string &s);

        void FromString(const std::string &str);

        TBigInt &operator=(const TBigInt &other);
        TBigInt operator+(const TBigInt &other);
        TBigInt operator-(const TBigInt &other);
        TBigInt operator*(const TBigInt &other);
        static TBigInt KaratsubaMultiply(const TBigInt &lhs, const TBigInt &rhs);
        TBigInt operator/(int other);
        TBigInt operator/(const TBigInt &other);
        TBigInt &operator++();
        TBigInt operator++(int);
        TBigInt &operator--();
        TBigInt operator--(int);
        TBigInt &operator+=(const TBigInt &other);
        TBigInt &operator-=(const TBigInt &other);
        TBigInt &operator*=(const TBigInt &other);
        TBigInt &operator=(int other);
        TBigInt &operator/=(const TBigInt &other);
        bool operator==(const TBigInt &other);
        bool operator!=(const TBigInt &other);
        bool operator<(const TBigInt &other);
        bool operator>(const TBigInt &other);
        bool operator<=(const TBigInt &other);
        bool operator>=(const TBigInt &other);

        friend std::ostream &operator<<(std::ostream &out, const TBigInt &num);
        friend std::istream &operator>>(std::istream &in, TBigInt &num);
    };

    std::ostream &operator<<(std::ostream &out, const TBigInt &num);
    std::istream &operator>>(std::istream &in, TBigInt &num);
} // namespace ystd
