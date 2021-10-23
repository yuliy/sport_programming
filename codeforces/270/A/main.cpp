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
    return (360 % a) == 0;
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