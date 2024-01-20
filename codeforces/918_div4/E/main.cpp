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


inline bool odd(ui64 num) {
    return (num & 1) == 1;
}

ui64 CalcOddSum(int l, int r, const vector<ui64>& a) {
    return (odd(r) ? a[r] : a[r-1])
        - (odd(l) ? a[l-2] : a[l-1]);
}

ui64 CalcEvenSum(int l, int r, const vector<ui64>& a) {
    return (odd(r) ? a[r-1] : a[r])
        - (odd(l) ? a[l-1] : a[l-2]);
}


void Solve(int n, const vector<ui64>& a) {
    for (int l = 2; l < (n+2); ++l) {
        for (int r = l+1; r < (n+2); ++r) {
            if (CalcOddSum(l, r, a) == CalcEvenSum(l, r, a)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ui64 t;
    cin >> t;
    string s;
    for (ui64 i = 0; i < t; ++i) {
        ui64 n;
        cin >> n;
        vector<ui64> a(n+2);
        a[0] = a[1] = 0;
        for (int j = 2; j < (n+2); ++j) {
            cin >> a[j];
            a[j] += a[j-2];
        }

        Solve(n, a);
    }

    return 0;
}
