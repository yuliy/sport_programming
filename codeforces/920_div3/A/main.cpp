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
        vector<pair<int, int>> v(4);
        for (int j = 0; j < 4; ++j)
            cin >> v[j].first >> v[j].second;
        sort(v.begin(), v.end());

        const int a = v[0].second - v[1].second;
        cout << (a*a) << endl;
    }

    return 0;
}
