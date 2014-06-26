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

int Pow(int a, int p) {
    int res = 1;
    for (; p; p >>= 1, a *= a)
        if (p & 1)
            res *= a;
    return res;
}

const long long MOD = 1000000007;

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

int main() {
    int n;
    string s, w;
    cin >> n >> s >> w;

    int qcount = 0;
    bool less_case = false;
    bool greater_case = false;
    for (int i = 0; i < n; ++i) {
        const char sch = s[i];
        const char wch = w[i];
        if (sch == '?' && wch == '?') {
            qcount += 2;
        } else if (sch == '?') {
            ++qcount;
        } else if (wch == '?') {
            ++qcount;
        } else {
            if (sch < wch)
                less_case = true;
            if (sch > wch)
                greater_case = true;
        }
    }

    long long res = 0;
    if (less_case && greater_case) {
        // TODO
    }

    return 0;
}
