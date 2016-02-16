#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

using i64 = long long;

bool Check(i64 v, i64 x, i64 y) {
    if (v == 0)
        return false;

    const i64 tmp = y * 98 - v*v * 10;
    const i64 left = tmp * tmp;
    const i64 right = 98 * 98 * (x*x + y*y);
    return left >= right;
}

bool Solve() {
    i64 v, x0, y0, x1, y1, x2, y2;
    cin >> v
        >> x0 >> y0
        >> x1 >> y1
        >> x2 >> y2;

    if (!Check(v, x1-x2, y1-y2))
        return false;

    if (!Check(v, x2-x1, y2-y1))
        return false;

    return Check(v, x0-x1, y0-y1) || Check(v, x0-x2, y0-y2);
}

int main() {
    cout << (Solve() ? "Yes" : "No") << endl;
    return 0;
}
