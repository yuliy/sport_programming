#include <iostream>
#include <exception>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <heap_sort.h>
using namespace std;
using namespace ystd;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

int main( int argc, char** argv ) {
    try {
        //srand(time(NULL));
        THeap<int>();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
