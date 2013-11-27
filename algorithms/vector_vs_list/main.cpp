#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>

using namespace std;

typedef unsigned int ui32;
typedef long long i64;

static i64 GetTickCount() {
    return clock() * 1000000 / CLOCKS_PER_SEC;
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
        return (GetTickCount() - Start) * 0.000001;
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
    vector<ui32> vec;
    for (int i = 0; i < N; ++i)
        vec.push_back(rand());

    list<ui32> lst(vec.begin(), vec.end());

    TTimePrinter tp;
    const ui32 res1 = accumulate(vec.begin(), vec.end(), 0);
    tp.PrintTime();
    const ui32 res2 = accumulate(lst.begin(), lst.end(), 0);
    tp.PrintTime();

    cout << "Correct: " << ((res1 == res2) ? "yes" : "no") << endl;
    if (N < 10) {
        cout << "\tv1:" << endl;
        Print(vec);
        cout << "\tv2:" << endl;
        Print(lst);
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
