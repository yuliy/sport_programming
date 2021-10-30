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
    vector< pair<int, int> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int prev = 0;
    for (const auto& elem : v) {
        const int ai = elem.first;
        const int bi = elem.second;
        const int next = (prev <= bi) ? bi : ai;
        prev = next;
    }

    cout << prev << endl;

    return 0;
}
