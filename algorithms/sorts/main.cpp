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

#include <heap.h>
#include <heap_sort.h>

using namespace std;
using namespace ystd;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

static void SortsTest(int n) {
    //
}

static void TestHeapSort() {
    vector<int> v;
    v.push_back(5);
    v.push_back(13);
    v.push_back(2);
    v.push_back(25);
    v.push_back(7);
    v.push_back(17);
    v.push_back(20);
    v.push_back(8);
    v.push_back(4);
    HeapSort(v.begin(), v.end());
    std::copy(
        v.begin(), v.end(),
        ostream_iterator<int> (cout, "\t")
    );
}

int main( int argc, char** argv ) {
    try {
        //srand(time(NULL));
        //for (int i = 1024; i < 1e9; i <<= 1)
        //    SortsTest(i);
        TestHeapSort();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
