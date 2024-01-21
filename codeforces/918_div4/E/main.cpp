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
#include <map>
using namespace std;

using ui64 = unsigned long long;
using i64 = long long;


inline bool odd(i64 num) {
    return (num & 1) == 1;
}

bool Solve() {
    i64 n;
    cin >> n;
    i64 sum = 0;
    map<i64, i64> m;
    m[0] = 1;

    bool res = false;
    for (int i = 0; i < n; ++i) {
        i64 tmp;
        cin >> tmp;
        if (odd(i))
            sum -= tmp;
        else
            sum += tmp;

        if (m[sum]) {
            res = true;
        } else {
            ++m[sum];
        }

    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    i64 t;
    cin >> t;
    for (i64 i = 0; i < t; ++i)
        cout << (Solve() ? "YES" : "NO") << endl;

    return 0;
}
