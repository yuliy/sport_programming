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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ui64 n, m;
    cin >> n >> m;

    vector<ui64> vn(5);
    vector<ui64> vm(5);

    for (ui64 i = 1; i <= n; ++i) {
        vn[i % 5] += 1;
    }

    for (ui64 i = 1; i <= m; ++i) {
        vm[i % 5] += 1;
    }

    ui64 res = 0;
    for (ui64 i = 0; i < 5; ++i) {
        for (ui64 j = 0; j < 5; ++j) {
            const ui64 tmp = (i+j) % 5;
            if (0 == tmp) {
                res += (vn[i] * vm[j]);
            }
        }
    }

    cout << res << endl;

    return 0;
}
