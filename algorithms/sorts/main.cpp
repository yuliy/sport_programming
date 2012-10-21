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
#include <radix_sort.h>

using namespace std;
using namespace ystd;

typedef unsigned int ui32;
typedef long long i64;

static i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

template<typename TIterator>
void FillRandom(TIterator beg, TIterator end) {
    for (TIterator iter = beg; iter != end; ++iter)
        *iter = rand() % 100;
}

template<typename TIterator>
bool CheckSorted(TIterator beg, TIterator end) {
    TIterator iter = beg;
    TIterator prev = beg;
    ++iter;
    for (; iter != end; ++iter) {
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

static void SortsTest(size_t n) {
    vector<int> v(n);

    cout << "======================================================================" << endl;
    cout << "n=" << n/1024 << "K" << endl;

    {
        const int start = GetTickCount();
        FillRandom(v.begin(), v.end());
        std::sort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "std::sort\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v.begin(), v.end());
    }

    /*
    {
        FillRandom(v.begin(), v.end());
        const int start = GetTickCount();
        qsort(&v[0], v.size(), sizeof(int), compare);
        const int time = GetTickCount() - start;
        cout << "qsort\t\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v.begin(), v.end());
    }

    {
        FillRandom(v.begin(), v.end());
        const int start = GetTickCount();
        HeapSort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "HeapSort\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v.begin(), v.end());
    }

    {
        FillRandom(v.begin(), v.end());
        const int start = GetTickCount();
        QuickSort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "QuickSort\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v.begin(), v.end());
    }
    */

    {
        vector<ui32> v(n);
        FillRandom(v.begin(), v.end());
        const int start = GetTickCount();
        RadixSort(v.begin(), v.end());
        const int time = GetTickCount() - start;
        cout << "RadixSort\t" << time/1000.0 << " sec" << endl;
        CheckSorted(v.begin(), v.end());
    }
}

static void TestRadixSort() {
    vector<ui32> v(10);
    FillRandom(v.begin(), v.end());
    RadixSort(v.begin(), v.end());
    CheckSorted(v.begin(), v.end());
}

int main( int argc, char** argv ) {
    try {
        srand(time(NULL));
        for (size_t i = 128*1024; i < 1e9; i <<= 1)
            SortsTest(i);
        //TestRadixSort();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
