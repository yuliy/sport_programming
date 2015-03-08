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

typedef long long i64;

static bool solve(i64 n, i64 k, i64 d1, i64 d2) {
    return (d1 + d2 + abs(d1-d2)) <= (n-k);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        i64 n, k, d1, d2;
        //scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
        cin >> n >> k >> d1 >> d2;
        if (solve(n, k, d1, d2)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
