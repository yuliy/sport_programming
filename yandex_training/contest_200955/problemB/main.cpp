#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

/*
long long Pow(long long a, int p) {
    long long res = 1;
    for (; p; p >>= 1, a *= a, a %= MOD) {
        if (p & 1) {
            res *= a;
            res %= MOD;
        }
    }
    return res;
}
*/

void CountCases(char a, char b, long long &less, long long &greater, long long &any) {
    less = greater = any = 0;
    if (a == '?' && b == '?') {
        any = 100;
        less = 45;
        greater = 45;
    } else if (a == '?') {
        any = 10;
        less = b - '0';
        greater = 9 - less;
    } else if (b == '?') {
        any = 10;
        greater = a - '0';
        less = 9 - greater;
    } else {
        any = 1;
        if (a < b) less = 1;
        if (a > b) greater = 1;
    }
}

inline long long Add(long long a, long long b) {
    return (a + b) % MOD;
}

inline long long Mult(long long a, long long b) {
    return (a * b) % MOD;
}

int main() {
    int n;
    string s, w;
    cin >> n >> s >> w;

    long long ncc = 0;
    long long lcc = 0;
    long long gcc = 0;
    long long bcc = 0;

    long long tmp = 0;
    const char a = s[0];
    const char b = w[0];
    CountCases(a, b, lcc, gcc, tmp);
    if (!lcc && !gcc)
        ++ncc;
    if (lcc && gcc)
        ++bcc;

    for (int i = 1; i < n; ++i) {
        cout << "===========================" << endl
            << "i=" << i << endl
            << "ncc=" << ncc << endl
            << "lcc=" << lcc << endl
            << "gcc=" << gcc << endl
            << "bcc=" << bcc << endl;

        const char a = s[i];
        const char b = w[i];
        long long less, greater, any;
        CountCases(a, b, less, greater, any);
        long long eq = any - less - greater;

        lcc = Add(lcc, Mult(ncc, less));
        lcc = Add(lcc, Mult(lcc, less));
        bcc = Add(bcc, Mult(gcc, less));
        bcc = Add(bcc, Mult(bcc, less));

        gcc = Add(gcc, Mult(ncc, greater));
        gcc = Add(gcc, Mult(gcc, greater));
        bcc = Add(bcc, Mult(lcc, greater));
        bcc = Add(bcc, Mult(bcc, greater));

        if (eq) {
            ncc = Mult(ncc, eq);
            lcc = Mult(lcc, eq);
            gcc = Mult(gcc, eq);
            bcc = Mult(bcc, eq);
        }

        cout << "-------------------" << endl
            << "i=" << i << endl
            << "ncc=" << ncc << endl
            << "lcc=" << lcc << endl
            << "gcc=" << gcc << endl
            << "bcc=" << bcc << endl;
    }

    cout << bcc << endl;

    return 0;
}
