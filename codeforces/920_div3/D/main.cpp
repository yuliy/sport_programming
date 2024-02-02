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
        i64 n, m;
        cin >> n >> m;
        vector<i64> a(n);
        vector<i64> b(m);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        i64 res = 0;
        for (int i=0, j=0; (i+j) < n; ) {
            const i64 lsum = abs(a[i] - b[i]);
            const i64 rsum = abs(a[n-j-1] - b[m-j-1]);
            if (lsum >= rsum) {
                res += lsum;
                ++i;
            } else {
                res += rsum;
                ++j;
            }
        }
        cout << res << endl;
    }

    return 0;
}

