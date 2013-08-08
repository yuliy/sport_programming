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

template<typename TCont>
void Print(TCont &cont) {
    for (typename TCont::const_iterator iter = cont.begin(); iter != cont.end(); ++iter) {
        cout << *iter << "\t" << endl;
    }
}

static void Test() {
    const int N = 1000000;
    vector<ui32> v1;
    for (int i = 0; i < N; ++i)
        v1.push_back(rand());

    vector<ui32> v2(v1);

    TTimePrinter tp;
    RadixSort(v1);
    tp.PrintTime();
    std::sort(v2.begin(), v2.end());
    tp.PrintTime();

    cout << "Correct: " << ((v1 == v2) ? "yes" : "no") << endl;
    if (N < 1024) {
        cout << "\tv1:" << endl;
        Print(v1);
        cout << "\tv2:" << endl;
        Print(v2);
    }
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
