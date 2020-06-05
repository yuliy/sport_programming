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

int Solve(int n, vector<int>& s) {
    sort(s.begin(), s.end());
    vector<int> sn(n);
    for (int k = 1; k <= 1024; ++k) {
        for (int i = 0; i < n; ++i) {
            sn[i] = s[i] ^ k;
        }
        sort(sn.begin(), sn.end());
        if (s == sn) {
            return k;
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> s;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        cout << Solve(n, s) << endl;
    }

    return 0;
}
