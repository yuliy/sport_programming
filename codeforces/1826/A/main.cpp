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

static int Solve(int n, const vector<int> &a)
{
    map<int, int> p2c;
    for (auto p : a)
        p2c[p] += 1;

    if (p2c.size() == 1)
    {
        const auto p = a[0];
        if (p == 0)
            return 0;
        if (p > n)
            return n;
        return -1;
    }

    int f = 0;
    for (auto it = p2c.rbegin(); it != p2c.rend(); ++it)
    {
        auto prev_it = it;
        ++prev_it;
        if (prev_it == p2c.rend())
            break;

        const int pj = it->first;
        f += p2c[pj];
        const int pk = prev_it->first;
        //cout << "pj=" << pj << "\tf=" << f << "\tpk=" << pk << endl;

        if (pj > f && pk <= f)
            return f;
    }

    return -1;
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
