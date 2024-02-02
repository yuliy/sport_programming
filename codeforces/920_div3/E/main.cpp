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

    cout << "_________________________" << endl;
    cout
        << "h=" << h << " w=" << w
        << " xa=" << xa << " ya=" << ya
        << " xb=" << xb << " yb=" << yb
        << endl;

    if (xa >= xb)
        return "draw";

    const i64 dy = abs(ya - yb);
    const i64 dx = abs(xa - xb);
    if (dy > 1)
        return "draw";

    const bool even = (dx & 1) == 0;
    if (dy == 1) {
        if (even) {
            if ((ya < yb) && (yb < w))
                return "draw";
            if ((ya > yb) && (yb > 1))
                return "draw";
            return "alice";
        } else {
            if ((ya < yb) && (ya > 1))
                return "draw";
            if ((ya > yb) && (ya < w))
                return "draw";
            return "bob";
        }
    }

    //if (dy == 0)
    return even ? "alice" : "bob";
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

