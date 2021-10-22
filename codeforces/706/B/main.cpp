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

static int Solve(int n, int mi, const vector<int>& x) {
    const auto it = upper_bound(x.begin(), x.end(), mi);
    return it - x.begin();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q, mi;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    std::sort(x.begin(), x.end());

    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> mi;
        cout << Solve(n, mi, x) << endl;
    }

    return 0;
}
