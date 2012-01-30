#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ui64;

static bool IsPrime(long long num) {
    const long long max = sqrt(num) + 1;
    for (long long i = 2; i <= max; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

/*
static long long MAGIC_NUM = (1LL << 11) - 1;

static bool IsPandigit(long long num) {
    for (long long i = 0; i < 10; ++i) {

    }
    return false;
}
*/

int main() {
    const long long b0 = 1;
    const long long b1 = b0 * 10;
    const long long b2 = b1 * 10;
    const long long b3 = b2 * 10;
    const long long b4 = b3 * 10;
    const long long b5 = b4 * 10;
    const long long b6 = b5 * 10;

    for (ui64 i6 = 7; i6 >= 1; --i6) {
    for (ui64 i5 = 7; i5 >= 1; --i5) {
        if (i5 == i6)
            continue;
    for (ui64 i4 = 7; i4 >= 1; --i4) {
        if (i4 == i5 || i4 == i6)
            continue;
    for (ui64 i3 = 7; i3 >= 1; --i3) {
        if (i3 == i4 || i3 == i5 || i3 == i6)
            continue;
    for (ui64 i2 = 7; i2 >= 1; --i2) {
        if (i2 == i3 || i2 == i4 || i2 == i5 || i2 == i6)
            continue;
    for (ui64 i1 = 7; i1 >= 1; --i1) {
        if (i1 == i2 || i1 == i3 || i1 == i4 || i1 == i5 || i1 == i6)
            continue;
    for (ui64 i0 = 7; i0 >= 1; --i0) {
        if (i0 == i1 || i0 == i2 || i0 == i3 || i0 == i4 || i0 == i5 || i0 == i6)
            continue;
        const long long num =   i6 * b6 + 
                                i5 * b5 +
                                i4 * b4 +
                                i3 * b3 +
                                i2 * b2 +
                                i1 * b1 +
                                i0 * b0;
        //cout << num << endl;
        if (IsPrime(num)) {
            cout << "Result=" << num << endl;
            return 0;
        }
    }
    }
    }
    }
    }
    }
    }

    cout << "No solutions found." << endl;
    return 0;
}
