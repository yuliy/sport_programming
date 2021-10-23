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

static bool Solve(int a) {
    if (a < 60)
        return false;

    for (int n = 3; ; ++n) {
        const int s = 180 * (n-2);
        const int c = a * n;
        if (c == s)
            return true;
        else if (c < s)
            return false;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, a;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a;
        cout << (Solve(a) ? "YES" : "NO") << endl;
    }

    return 0;
}
