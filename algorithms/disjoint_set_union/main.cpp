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

#include <disjoint_set_union.h>

using namespace std;

typedef unsigned int ui32;
typedef long long i64;

static i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

static void Test() {
    ystd::TDisjointSetUnion<int> dsu;

    for (int i = 0; i < 5; ++i)
        dsu.MakeSet(i);

    ystd::TDisjointSetUnion<int>::TPNodes &ns = dsu.PNodes;

    cout << "Unions: " << endl;
    cout << dsu.Union(ns[0], ns[1]) << endl;
    cout << dsu.Union(ns[2], ns[3]) << endl;
    cout << dsu.Union(ns[0], ns[3]) << endl;

    cout << "Finds: " << endl;
    cout << (dsu.FindSet(ns[0]) == dsu.FindSet(ns[2])) << endl;
    cout << (dsu.FindSet(ns[0]) == dsu.FindSet(ns[4])) << endl;
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
