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

void FillRandom(vector<int> &v) {
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        *iter = rand();
}

static int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

static void SortsTest(int n) {
    vector<int> v(n);

    cout << "======================================================================" << endl;
    cout << "n=" << n/1024 << "K" << endl;

    {
        const int start = GetTickCount();
        FillRandom(v);
        std::sort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "std::sort\t" << time/1000.0 << " sec" << endl;
    }

    {
        const int start = GetTickCount();
        FillRandom(v);
        qsort(&v[0], v.size(), sizeof(int), compare);
        const int time = GetTickCount() - start;
        cout << "qsort\t\t" << time/1000.0 << " sec" << endl;
    }

    {
        const int start = GetTickCount();
        FillRandom(v);
        HeapSort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "HeapSort\t" << time/1000.0 << " sec" << endl;
    }
}

/*
static void TestHeap() {
    THeap<int> h;
    const int arr[] = {4, 1, 3, 2, 16, 10, 9, 14, 8, 7};
    const int CNT = sizeof(arr) / sizeof(int);
    for (int i = 0; i < CNT; ++i) {
        h.Insert(arr[i]);
        cout << "max=" << h.Root() << endl;
    }
}
*/

int main( int argc, char** argv ) {
    try {
        srand(time(NULL));
        for (int i = 128*1024; i < 1e9; i <<= 1)
            SortsTest(i);
        //TestHeap();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
