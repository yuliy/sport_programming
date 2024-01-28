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


bool Solve(i64 n, i64 f, i64 a, i64 b, const vector<i64> &m) {
    //
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        i64 n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<i64> m(n);
        for (int j = 0; j < n; ++j)
            cin >> m[j];
        cout << (Solve(n, f, a, b, m) ? "YES" : "NO") << endl;
    }

    return 0;
}
