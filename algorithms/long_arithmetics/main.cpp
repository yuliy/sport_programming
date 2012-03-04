#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
using namespace std;

typedef unsigned int ui32;

class TBigIntException : public std::exception {
private:
    string Desc;
private:
    TBigIntException();
public:
    explicit TBigIntException(const char *desc)
        : Desc(desc) {
    }

    ~TBigIntException() throw() {
    }

    const char *what() const throw() {
        return Desc.c_str();
    }
};

class TBigInt {
private:
    typedef vector<int> TDigits;
    typedef TDigits::iterator TIter;
    typedef TDigits::const_iterator TCIter;
    typedef TDigits::reverse_iterator TRIter;
    typedef TDigits::const_reverse_iterator TCRIter;
private:
    TDigits Digits;
    static const int BASE = 10000;
    static const int BASE_DIGITS_CNT = 4;
private:
    void Normalize() {
        while (Digits.size() && Digits.back() == 0)
            Digits.pop_back();
    }

    static void Divide(const TBigInt &a, int b, TBigInt &res, int &remainder) {
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

    static void Divide(const TBigInt &a, const TBigInt &b, TBigInt &res, TBigInt &remainder) {
        //
    }
public:
    TBigInt() {
    }

    TBigInt(const TBigInt &other)
        : Digits(other.Digits) {
    }

    TBigInt(int num) {
        while (num) {
            Digits.push_back(num % BASE);
            num /= BASE;
        }
    }

    TBigInt(long long num) {
        while (num) {
            Digits.push_back(num % BASE);
            num /= BASE;
        }
    }

    TBigInt &operator=(const TBigInt &other) {
        Digits = other.Digits;
        return *this;
    }

    TBigInt operator+(const TBigInt &other) {
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

    TBigInt operator-(const TBigInt &other) {
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

    TBigInt operator*(const TBigInt &other) {
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

    TBigInt operator/(int other) {
        TBigInt res;
        int remainder;
        Divide(*this, other, res, remainder);
        return res;
    }

    TBigInt operator/(const TBigInt &other) {
        // TODO
    }

    //TBigInt &operator++() {
    //}

    //TBigInt &operator++(int) {
    //}

    //TBigInt operator--() {
    //}

    //TBigInt operator--(int) {
    //}

    TBigInt &operator+=(const TBigInt &other) {
        *this = *this + other;
        return *this;
    }

    TBigInt &operator-=(const TBigInt &other) {
        *this = *this - other;
        return *this;
    }

    TBigInt &operator*=(const TBigInt &other) {
        *this = *this * other;
        return *this;
    }

    TBigInt &operator=(int other) {
        *this = *this / other;
        return *this;
    }

    TBigInt &operator/=(const TBigInt &other) {
        *this = *this / other;
        return *this;
    }

    //bool operator==(const TBigInt &other) {
    //}

    //bool operator!=(const TBigInt &other) {
    //    return !(*this == other);
    //}

    //bool operator<(const TBigInt &other) {
    //}

    //bool operator>(const TBigInt &other) {
    //}

    //bool operator<=(const TBigInt &other) {
    //}

    //bool operator>=(const TBigInt &other) {
    //}

    friend ostream &operator<<(ostream &ous, const TBigInt &num);
};

ostream &operator<<(ostream &ous, const TBigInt &num) {
    if (num.Digits.empty()) {
        ous << '0';
        return ous;
    }

    TBigInt::TCRIter beg = num.Digits.rbegin(),
                     end = num.Digits.rend();
    for (TBigInt::TCRIter iter = beg; iter != end; ++iter) {
        if (iter != beg)
            ous << setfill('0') << setw(TBigInt::BASE_DIGITS_CNT);
        ous << *iter;
    }
    return ous;
}

int main( int argc, char** argv ) {
    try {
        TBigInt a = 2000000000;
        //TBigInt b = 100000;
        cout << a << endl;
        //cout << b << endl;
        cout << a / 1000000000 << endl;

    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
