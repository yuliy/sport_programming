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

using ui64 = unsigned long long;
using i64 = long long;

static i64 SolveInterval(i64 m, i64 k) {
    return (m > 0 && k <= m)
        ? (m - k + 1) * (m - k + 2) / 2
        : 0;
}

static i64 Solve(i64 n, i64 k, i64 q, const vector<i64> &a) {
    i64 res = 0;
    i64 m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= q) {
            ++m;
        } else {
            res += SolveInterval(m, k);
            m = 0;
        }
    }

    if (m > 0)
        res += SolveInterval(m, k);

    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        i64 n, k, q;
        cin >> n >> k >> q;
        vector<i64> a(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        cout << Solve(n, k, q, a) << endl;
    }

    return 0;
}
