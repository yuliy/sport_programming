#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned int ui32;

template<typename DigitType, int BASE, int NUM_LENGTH>
class TBigUInt {
private:
    int Base;
    vector<DigitType> Digits;
    typedef vector<DigitType> TDigits;
    typedef typename vector<DigitType>::iterator TDIter;
    typedef typename vector<DigitType>::const_iterator TDConstIter;
public:
    TBigUInt()
        : Base(BASE)
        , Digits(NUM_LENGTH) {
    }

    TBigUInt(const TBigUInt &other)
        : Base(BASE)
        , Digits(NUM_LENGTH) {
        copy(other.Digits.begin(), other.Digits.end(), Digits.begin());
    }

    TBigUInt(const DigitType &shortNum);

    TBigUInt &operator=(const TBigUInt &other);

    template<typename DT, int BS, int NL>
    friend ostream &operator<<(ostream &ous, TBigUInt<DT, BS, NL> &num);
};

template<typename DigitType, int BASE, int NUM_LENGTH>
ostream &operator<<(ostream &ous, TBigUInt<DigitType, BASE, NUM_LENGTH> &num) {
    ous << "debug";
    return ous;
}

typedef TBigUInt<ui32, 10000, 100> TBigNum;

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
