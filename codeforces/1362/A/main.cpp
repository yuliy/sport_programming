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
#include <cstdlib>
#include <tuple>
using namespace std;

using ui64 = unsigned long long;
using i64 = long long;

tuple<i64, i64> Foo(i64 num) {
    i64 rank = 0;
    if (0 != num) {
        while (0 == (num & 1)) {
            num >>= 1;
            ++rank;
        }
    }
    return std::make_tuple(num, rank);
}

i64 CalcDiff(i64 r1, i64 r2) {
    i64 d = abs(r1 - r2);
    i64 res = 0;
    while (d >= 3) {
        res += 1;
        d -= 3;
    }

    while (d >= 2) {
        res += 1;
        d -= 2;
    }

    while (d >= 1) {
        res += 1;
        d -= 1;
    }

    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        i64 a, b;
        cin >> a >> b;
        auto f1 = Foo(a);
        auto f2 = Foo(b);
        if (get<0>(f1) == get<0>(f2)) {
            cout <<  CalcDiff(get<1>(f1), get<1>(f2)) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
