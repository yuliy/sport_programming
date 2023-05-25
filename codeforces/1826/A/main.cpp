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

static pair<int, int> Count(int p, const vector<int> &a)
{
    int equal = 0;
    int greater = 0;
    for (auto elem : a)
    {
        if (elem == p)
            ++equal;
        if (elem > p)
            ++greater;
    }
    return make_pair(equal, greater);
}

static int Solve(int n, const vector<int> &a)
{
    for (auto p : a)
    {
        const auto [eq, gr] = Count(p, a);
        if (gr >= p)
            return gr;
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
