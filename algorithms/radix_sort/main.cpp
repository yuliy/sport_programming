#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>

#include "radix.h"

using namespace std;
using namespace ystd;

typedef long long i64;

static i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

class TTimePrinter {
    i64 Start;
public:
    TTimePrinter()
        : Start(GetTickCount()) {
    }

    void PrintTime() const {
        cout << "\tTime: " << GetTime() << " sec" << endl;
    }

    double GetTime() const {
        return (GetTickCount() - Start) * 0.001;
    }
};

static void Test() {
    //
}

int main( int argc, char** argv ) {
    try {
        Test();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }
    return 0;
}
