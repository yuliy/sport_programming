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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector< pair<int, int> > v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        v.emplace_back(p, q);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < n; ++i) {
        if (v[i-1].second > v[i].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }

    cout << "Poor Alex" << endl;
    return 0;
}
