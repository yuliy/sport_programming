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
using namespace ystd;

int main( int argc, char** argv ) {
    try {
        TBigInt a, b;
        cin >> a >> b;
        cout << a << endl
            << b << endl;

        TBigInt c = a * b;
        cout << c << endl;

    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
