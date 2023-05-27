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


int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

static int Solve(int n, const vector<int> &a) {
    if (n == 1)
        return 0;

    int res = abs(a[0] - a[n-1]);
    for (int i = 1, j = n-2; i < j; ++i, --j)
    {
        const int next = abs(a[i] - a[j]);
        res = gcd(res, next);
    }

    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];

        cout << Solve(n, a) << endl;
    }

    return 0;
}
