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
#include <utility>
using namespace std;

using ui64 = unsigned long long;
using i64 = long long;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        i64 n, f, a, b;
        cin >> n >> f >> a >> b;

        i64 res = 0, prev = 0;
        for (int j = 0; j < n; ++j) {
            i64 next;
            cin >> next;
            res += min(a*(next - prev), b);
            prev = next;
        }

        cout << ((f > res) ? "YES" : "NO") << endl;
    }

    return 0;
}

