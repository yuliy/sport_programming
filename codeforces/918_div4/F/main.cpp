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
#include <map>
using namespace std;

using ui64 = unsigned long long;
using i64 = long long;
using Segment = pair<i64, i64>;


i64 Solve() {
    int n;
    cin >> n;
    vector< pair<i64, i64> > v;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(
        v.begin(), v.end(),
        [](const Segment& lhs, const Segment& rhs)
        { return lhs.first < rhs.first; }
    );

    set<Segment> s(
        [](const Segment& lhs, const Segment& rhs)
        { return lhs.second < rhs.second; }
    );

    for (const auto &segment : v) {

    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    i64 t;
    cin >> t;
    for (i64 i = 0; i < t; ++i)
        cout << Solve() << endl;

    return 0;
}
