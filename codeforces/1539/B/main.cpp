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

int Weight(char ch) {
    return ch - 'a' + 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<i64> v(n+1);
    v[0] = 0;
    for (int i = 0; i <= n; ++i) {
        const char ch = s[i];
        v[i+1] = v[i] + Weight(ch);
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        const auto res = v[r] - v[l-1];
        cout << res << endl;
    }


    return 0;
}
