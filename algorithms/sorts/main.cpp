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
#include <quick_sort.h>

using namespace std;
using namespace ystd;

typedef unsigned int ui32;
typedef long long i64;

static i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

static void FillRandom(vector<int> &v) {
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        *iter = rand();
}

static bool CheckSorted(const vector<int> &v) {
    vector<int>::const_iterator iter = v.begin();
    vector<int>::const_iterator prev = iter;
    ++iter;
    for (; iter != v.end(); ++iter) {
        if (*prev > *iter) {
            cout << "ACHTUNG!!! Array is not sorted!!!!!" << endl;
            return false;
        }
    }
    return true;
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
        CheckSorted(v);
    }

    {
        FillRandom(v);
        const int start = GetTickCount();
        qsort(&v[0], v.size(), sizeof(int), compare);
        const int time = GetTickCount() - start;
        cout << "qsort\t\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v);
    }

    {
        FillRandom(v);
        const int start = GetTickCount();
        HeapSort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "HeapSort\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v);
    }

    {
        FillRandom(v);
        const int start = GetTickCount();
        QuickSort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "QuickSort\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v);
    }
}

int main( int argc, char** argv ) {
    try {
        srand(time(NULL));
        for (int i = 128*1024; i < 1e9; i <<= 1)
            SortsTest(i);
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
