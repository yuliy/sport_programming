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

    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double res = max(v[0], l-v[n-1]);
    for (int i = 1; i < n; ++i) {
        const double tmp = 0.5 * (v[i] - v[i-1]);
        res = max(res, tmp);
    }

    printf("%f\n", res);
    return 0;
}
