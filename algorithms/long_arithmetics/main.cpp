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

template<typename DigitType, int BASE_DIGITS, int NUM_LENGTH>
class TBigUInt {
private:
    int BaseDigits;
    int Base;
    vector<DigitType> Digits;
    typedef vector<DigitType> TDigits;
    typedef typename vector<DigitType>::iterator TDIter;
    typedef typename vector<DigitType>::const_iterator TDConstIter;
    typedef typename vector<DigitType>::reverse_iterator TDReverseIter;
    typedef typename vector<DigitType>::const_reverse_iterator TDConstReverseIter;
public:
    TBigUInt()
        : BaseDigits(BASE_DIGITS)
        , Base(pow(10, BASE_DIGITS))
        , Digits(NUM_LENGTH) {

        Digits[0] = 100;
        Digits[1] = 1000;
        Digits[2] = 9999;
        Digits[3] = 70;
    }

    TBigUInt(const TBigUInt &other)
        : BaseDigits(BASE_DIGITS)
        , Base(pow(10, BASE_DIGITS))
        , Digits(NUM_LENGTH) {
        copy(other.Digits.begin(), other.Digits.end(), Digits.begin());
    }

    TBigUInt(const DigitType &shortNum);

    TBigUInt &operator=(const TBigUInt &other);

    template<typename DT, int BSDS, int NL>
    friend ostream &operator<<(ostream &ous, TBigUInt<DT, BSDS, NL> &num);
};

template<typename T>
struct TNotZero : public unary_function<T, bool> {
    bool operator()(const T &v) {
        return v != 0;
    }
};

static int DigitsCount(long long num) {
    int res = 0;
    while (num) {
        ++res;
        num /= 10;
    }
    return res;
}

template<typename DigitType, int BASE_DIGITS, int NUM_LENGTH>
ostream &operator<<(ostream &ous, TBigUInt<DigitType, BASE_DIGITS, NUM_LENGTH> &num) {
    typedef typename TBigUInt<DigitType, BASE_DIGITS, NUM_LENGTH>::TDConstReverseIter TIter;
    TIter end = num.Digits.rend();
    TIter start = num.Digits.rbegin();
    start = find_if(start, end, TNotZero<DigitType>());
    if (start != end) {
        for (TIter it = start; it != end; ++it) {
            if (it != start) {
                const int dcnt = DigitsCount(*it);
                const int nullsCount = BASE_DIGITS - dcnt;
                for (int i = 0; i < nullsCount; ++i)
                    ous << '0';
            }
            ous << *it;
        }
    } else {
        ous << '0';
    }
    return ous;
}

typedef TBigUInt<ui32, 4, 100> TBigNum;

int main( int argc, char** argv ) {
    try {
        TBigNum a;
        cout << a << endl;

    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
