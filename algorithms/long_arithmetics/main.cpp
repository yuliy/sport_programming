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

            res.Digits.push_back(t % BASE);
            carry = t / BASE;
        }

        if (carry)
            res.Digits.push_back(carry);

        return res;
    }

    //TBigInt operator-(const TBigInt &other) {
    //}

    //TBigInt operator*(const TBigInt &other) {
    //}

    //TBigInt operator/(const TBigInt &other) {
    //}

    //TBigInt &operator++() {
    //}

    //TBigInt &operator++(int) {
    //}

    //TBigInt operator--() {
    //}

    //TBigInt operator--(int) {
    //}

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
        TBigInt a = 5000005;
        TBigInt b = 5001100;
        cout << a << endl;
        cout << b << endl;
        cout << a + b << endl;

    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
