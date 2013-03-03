#include "bignum.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

namespace ystd {
    typedef unsigned int ui32;

    //
    // TBigIntException
    //

    TBigIntException::TBigIntException(const char *desc)
        : Desc(desc) {
    }

    TBigIntException::~TBigIntException() throw() {
    }

    const char *TBigIntException::what() const throw() {
        return Desc.c_str();
    }

    //
    // TBigInt
    //

    TBigInt::TBigInt() {
    }

    TBigInt::TBigInt(const TBigInt &other)
        : Digits(other.Digits) {
    }

    TBigInt::TBigInt(int num) {
        while (num) {
            Digits.push_back(num % BASE);
            num /= BASE;
        }
    }

    TBigInt::TBigInt(long long num) {
        while (num) {
            Digits.push_back(num % BASE);
            num /= BASE;
        }
    }

    TBigInt::TBigInt(const char *str) {
        const string s(str);
        FromString(s);
    }

    TBigInt::TBigInt(const string &str) {
        FromString(str);
    }

    void TBigInt::FromString(const std::string &str) {
        TDigits digits;
        const int len = str.size();
        int m = 1, tmp = 0, dcnt = 0;
        for (int pos = len - 1; pos >= 0; --pos) {
            const int digit = str[pos] - '0';
            tmp += digit * m;
            ++dcnt;
            if (dcnt == BASE_DIGITS_CNT) {
                m = 1;
                dcnt = 0;
                digits.push_back(tmp);
            } else {
                m *= 10;
            }
        }

        if (tmp)
            digits.push_back(tmp);

        Digits.swap(digits);
    }

    void TBigInt::Normalize() {
        while (Digits.size() && Digits.back() == 0)
            Digits.pop_back();
    }

    void TBigInt::Divide(const TBigInt &a, int b, TBigInt &res, int &remainder) {
        const int asize = a.Digits.size();
        res.Digits.resize(asize);
        remainder = 0;
        for (int i = asize - 1; i >= 0; --i) {
            const int t = remainder * BASE + a.Digits[i]; 
            res.Digits[i] = t / b;
            remainder = t - res.Digits[i] * b;
        }

        res.Normalize();
    }

    void TBigInt::Divide(const TBigInt &a, TBigInt b, TBigInt &res, TBigInt &remainder) {
        const int asize = a.Digits.size();
        const int bsize = b.Digits.size();

        // Special case 1.
        if (asize < bsize) {
            res.Digits.clear();
            return;
        }

        // Special case 2.
        if (bsize == 1) {
            Divide(a, b.Digits[0], res, remainder);
            return;
        }

        //
        TBigInt u(a);
        u.Digits.push_back(0);

        const int n = bsize;
        const int m = asize + 1 - bsize;

        const int scale = BASE  / (b.Digits[n-1] + 1);
        if (scale > 1) {
            u = u * scale;
            b = b * scale;
        }
    }

    TBigInt &TBigInt::operator=(const TBigInt &other) {
        Digits = other.Digits;
        return *this;
    }

    TBigInt TBigInt::operator+(const TBigInt &other) {
        TCIter  aiter   = Digits.begin(),
                aend    = Digits.end(),
                biter   = other.Digits.begin(),
                bend    = other.Digits.end();

        TBigInt res;
        int carry = 0;
        for (; aiter != aend || biter != bend;) {
            int t = carry;
            if (aiter != aend)
                t += *aiter++;
            if (biter != bend)
                t += *biter++;

            if (t >= BASE) {
                res.Digits.push_back(t - BASE);
                carry = 1;
            } else {
                res.Digits.push_back(t);
                carry = 0;
            }
        }

        if (carry)
            res.Digits.push_back(carry);

        return res;
    }

    TBigInt TBigInt::operator-(const TBigInt &other) {
        TCIter  aiter   = Digits.begin(),
                aend    = Digits.end(),
                biter   = other.Digits.begin(),
                bend    = other.Digits.end();

        TBigInt res;
        int carry = 0;
        for (; aiter != aend || biter != bend;) {
            int t = carry;
            if (aiter != aend)
                t += *aiter++;
            if (biter != bend)
                t -= *biter++;

            if (t < 0) {
                res.Digits.push_back(t + BASE);
                carry = -1;
            } else {
                res.Digits.push_back(t);
                carry = 0;
            }
        }

        if (carry)
            throw TBigIntException("TBigInt::operator- overflow!");

        res.Normalize();
        return res;
    }

    TBigInt TBigInt::operator*(const TBigInt &other) {
        const TDigits &a = Digits;
        const TDigits &b = other.Digits;
        const int asize = a.size();
        const int bsize = b.size();

        TBigInt res;
        res.Digits.resize(asize + bsize + 1);
        TDigits &c = res.Digits;

        int carry = 0;
        int i = 0, j = 0;
        for (i = 0; i < asize; ++i) {
            carry = 0;
            for (j = 0; j < bsize; ++j) {
                const int t = a[i] * b[j] + c[i+j] + carry;
                carry = t / BASE;
                c[i+j] = t - carry * BASE;
            }
            c[i+j] = carry;
        }

        res.Normalize();
        return res;
    }

    TBigInt TBigInt::operator/(int other) {
        TBigInt res;
        int remainder;
        Divide(*this, other, res, remainder);
        return res;
    }

    TBigInt TBigInt::operator/(const TBigInt &other) {
        // TODO
        throw TBigIntException("TBigInt::operator/ not implemented!");
    }

    //TBigInt &TBigInt::operator++() {
    //}

    //TBigInt &TBigInt::operator++(int) {
    //}

    //TBigInt TBigInt::operator--() {
    //}

    //TBigInt TBigInt::operator--(int) {
    //}

    TBigInt &TBigInt::operator+=(const TBigInt &other) {
        *this = *this + other;
        return *this;
    }

    TBigInt &TBigInt::operator-=(const TBigInt &other) {
        *this = *this - other;
        return *this;
    }

    TBigInt &TBigInt::operator*=(const TBigInt &other) {
        *this = *this * other;
        return *this;
    }

    TBigInt &TBigInt::operator=(int other) {
        *this = *this / other;
        return *this;
    }

    TBigInt &TBigInt::operator/=(const TBigInt &other) {
        *this = *this / other;
        return *this;
    }

    //bool TBigInt::operator==(const TBigInt &other) {
    //}

    //bool TBigInt::operator!=(const TBigInt &other) {
    //    return !(*this == other);
    //}

    //bool TBigInt::operator<(const TBigInt &other) {
    //}

    //bool TBigInt::operator>(const TBigInt &other) {
    //}

    //bool TBigInt::operator<=(const TBigInt &other) {
    //}

    //bool TBigInt::operator>=(const TBigInt &other) {
    //}

    ostream &operator<<(ostream &out, const TBigInt &num) {
        if (num.Digits.empty()) {
            out << '0';
            return out;
        }

        TBigInt::TCRIter beg = num.Digits.rbegin(),
                         end = num.Digits.rend();
        for (TBigInt::TCRIter iter = beg; iter != end; ++iter) {
            if (iter != beg)
                out << setfill('0') << setw(TBigInt::BASE_DIGITS_CNT);
            out << *iter;
        }
        return out;
    }

    istream &operator>>(istream &in, TBigInt &num) {
        string s;
        in >> s;
        num = TBigInt(s);
        return in;
    }
} // namespace ystd
