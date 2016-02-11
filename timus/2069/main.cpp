#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

int Max(const vector<int>& v) {
    int res = -1e9;
    for (int elem : v) {
        res = max(res, elem);
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    vector<int> h(m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &h[i]);
    }

    int res = max(
        min(v[0], h[m-1]),
        min(h[0], v[n-1])
    );
    res = max(
        res,
        min(h[0], min(h[m-1], Max(v)))
    );
    res = max(
        res,
        min(v[0], min(v[n-1], Max(h)))
    );
    cout << res << endl;

    return 0;
}
