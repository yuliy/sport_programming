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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree< \
        int, __gnu_pbds::null_type, \
        less<int>, \
        __gnu_pbds::rb_tree_tag, \
        __gnu_pbds::tree_order_statistics_node_update \
    > \
    ordered_set;

using ui64 = unsigned long long;
using i64 = long long;
using Segment = pair<i64, i64>;


i64 Solve() {
    int n;
    cin >> n;
    vector< pair<i64, i64> > v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());

    ordered_set s;
    i64 res = 0;
    for (auto [bi, ai] : v) {
        // s.order_of_key(ai) - Number of items strictly smaller than ai
        res += s.size() - s.order_of_key(ai);
        s.insert(ai);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    i64 t;
    cin >> t;
    for (i64 i = 0; i < t; ++i)
        cout << Solve() << endl;

    return 0;
}
