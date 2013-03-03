#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>

#include "bignum.h"

using namespace std;

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
