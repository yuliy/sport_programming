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
    TBigInt()
        : Digits(0) {
    }

    TBigInt(const TBigInt &other)
        : Digits(other.Digits) {
    }

    TBigInt(int num) {
        if (num == 0) {
            Digits.push_back(0);
            return;
        }

        while (num) {
            Digits.push_back(num % BASE);
            num /= BASE;
        }
    }

    TBigInt(long long num) {
        if (num == 0) {
            Digits.push_back(0);
            return;
        }

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
        // TODO
    }

    TBigInt operator-(const TBigInt &other) {
        // TODO
    }

    TBigInt operator*(const TBigInt &other) {
        // TODO
    }

    TBigInt operator/(const TBigInt &other) {
        // TODO
    }

    TBigInt &operator++() {
        // TODO
    }

    TBigInt &operator++(int) {
        // TODO
    }

    TBigInt operator--() {
        // TODO
    }

    TBigInt operator--(int) {
        // TODO
    }

    bool operator==(const TBigInt &other) {
        // TODO
    }

    bool operator!=(const TBigInt &other) {
        return !(*this == other);
    }

    bool operator<(const TBigInt &other) {
        // TODO
    }

    bool operator>(const TBigInt &other) {
        // TODO
    }

    bool operator<=(const TBigInt &other) {
        // TODO
    }

    bool operator>=(const TBigInt &other) {
        // TODO
    }

    friend ostream &operator<<(ostream &ous, const TBigInt &num);
};

ostream &operator<<(ostream &ous, const TBigInt &num) {
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
        TBigInt a(50005);
        TBigInt b;
        b = a;
        cout << a << endl;
        cout << b << endl;

    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
