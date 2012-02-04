#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long long res = 0;

    for (long long d1 = 1; d1 < 10LL; ++d1) {
        cout << "d1 = " << d1 << endl;
    for (long long d2 = 0; d2 < 10LL; ++d2) {
        if (d2 == d1)
            continue;
    for (long long d3 = 0; d3 < 10LL; ++d3) {
        if (d3 == d1 || d3 == d2)
            continue;
    for (long long d4 = 0; d4 < 10LL; ++d4) {
        if (d4 == d1 || d4 == d2 || d4 == d3)
            continue;
    for (long long d5 = 0; d5 < 10LL; ++d5) {
        if (d5 == d1 || d5 == d2 || d5 == d3 || d5 == d4)
            continue;
    for (long long d6 = 0; d6 < 10LL; ++d6) {
        if (d6 == d1 || d6 == d2 || d6 == d3 || d6 == d4 || d6 == d5)
            continue;
    for (long long d7 = 0; d7 < 10LL; ++d7) {
        if (d7 == d1 || d7 == d2 || d7 == d3 || d7 == d4 || d7 == d5 || d7 == d6)
            continue;
    for (long long d8 = 0; d8 < 10LL; ++d8) {
        if (d8 == d1 || d8 == d2 || d8 == d3 || d8 == d4 || d8 == d5 || d8 == d6 || d8 == d7)
            continue;
    for (long long d9 = 0; d9 < 10LL; ++d9) {
        if (d9 == d1 || d9 == d2 || d9 == d3 || d9 == d4 || d9 == d5 || d9 == d6 || d9 == d7 || d9 == d8)
            continue;
    for (long long d10 = 0; d10 < 10LL; ++d10) {
        if (d10 == d1 || d10 == d2 || d10 == d3 || d10 == d4 || d10 == d5 || d10 == d6 || d10 == d7 || d10 == d8 || d10 == d9)
            continue;

        //cout << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << d9 << d10 << endl;
        //continue;

        /*
        d2d3d4=406 is divisible by 2
        d3d4d5=063 is divisible by 3
        d4d5d6=635 is divisible by 5
        d5d6d7=357 is divisible by 7
        d6d7d8=572 is divisible by 11
        d7d8d9=728 is divisible by 13
        d8d9d10=289 is divisible by 17
        */

        if ((d2 * 100 + d3 * 10 + d4) % 2)
            continue;

        if ((d3 * 100 + d4 * 10 + d5) % 3)
            continue;

        if ((d4 * 100 + d5 * 10 + d6) % 5)
            continue;

        if ((d5 * 100 + d6 * 10 + d7) % 7)
            continue;

        if ((d6 * 100 + d7 * 10 + d8) % 11)
            continue;

        if ((d7 * 100 + d8 * 10 + d9) % 13)
            continue;

        if ((d8 * 100 + d9 * 10 + d10) % 17)
            continue;

        res += (d1 * 1000000000LL +
                d2 * 100000000LL +
                d3 * 10000000LL +
                d4 * 1000000LL +
                d5 * 100000LL +
                d6 * 10000LL +
                d7 * 1000LL +
                d8 * 100LL +
                d9 * 10LL +
                d10);
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }

    cout << "Result = " << res << endl;

    return 0;
}
