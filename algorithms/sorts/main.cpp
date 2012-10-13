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
        deque<int> cont;
        cont.push_back(4);
        cont.push_back(1);
        cont.push_back(3);
        cont.push_back(2);
        cont.push_back(16);
        cont.push_back(9);
        cont.push_back(10);
        cont.push_back(14);
        cont.push_back(8);
        cont.push_back(7);
        THeap<int> h(cont.begin(), cont.end());
        h.Print();
        THeap<int> h2(h);
        h2.Print();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
