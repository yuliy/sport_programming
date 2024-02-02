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
#include <utility>
using namespace std;

using ui64 = unsigned long long;
using i64 = long long;

string Solve() {
    i64 h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    if (xa >= xb)
        return "draw";

    const i64 dx = abs(xa - xb);
    const bool bob_potential = (dx & 1) == 0;
    const i64 xm = bob_potential
        ? (xa + xb) / 2
        : (xa + xb) / 2 + 1;

    const i64 yma_right = min(ya + (xm - xa), w);
    const i64 yma_left = max(ya - (xm - xa), 1LL);
    const i64 ymb_right = min(yb - (xm - xb), w);;
    const i64 ymb_left = max(yb + (xm - xb), 1LL);

    if (bob_potential)
        return (yma_right > ymb_right || yma_left < ymb_left) ? "draw" : "bob";
    return (ymb_right > yma_right || ymb_left < yma_left) ? "draw" : "alice";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << Solve() << endl;
    }

    return 0;
}

