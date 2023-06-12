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

static i64 Solve(const i64 n, i64 k) {
    i64 i = 0, rem = n, c = 0;
    for (; i < k; ++i) {
        const i64 z = 1 << i;
        if (z <= rem) {
            rem -= z;
            ++c;
        } else {
            break;
        }
    }

    int res =  1 << c;
    rem = n - (1 << c);
    if ((i < k) && rem >= 0) {
        res += (rem == 0) ? 1 : Solve(rem, k);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        i64 n, k;
        cin >> n >> k;
        cout << Solve(n, k) << endl;
    }

    return 0;
}
