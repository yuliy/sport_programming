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

static int solve(vector<int> v)
{
    if (v.size() == 1)
        return 0;

    const auto beg = v.begin();
    const auto end = v.end();
    const auto min_it = min_element(beg, end);
    const auto max_it = max_element(beg, end);

    int l, m, r;
    if (min_it <= max_it)
    {
        l = min_it - beg + 1;
        m = max_it - min_it - 1;
        r = end - max_it;
    }
    else
    {
        l = max_it - beg + 1;
        m = min_it - max_it - 1;
        r = end - min_it;
    }

    cout
        << "min_it:" << (min_it - beg)
        << "\tmax_it:" << (max_it - beg)
        << "\tl:" << l
        << "\tm:" << m
        << "\tr:" << r
        << endl;

    return min(l+m, min(m+r, l+r));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int j = 0; j < N; ++j)
            cin >> v[j];

        cout << solve(v) << endl;
    }

    return 0;
}
