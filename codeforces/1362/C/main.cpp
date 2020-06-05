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

i64 Solve(i64 n) {
    i64 res = 0;
    i64 mult = 1;
    while (n / mult) {
        res += (n/mult);
        mult <<= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        i64 n;
        cin >> n;
        cout << Solve(n) << endl;
    }

    return 0;
}
