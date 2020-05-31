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

ui64 CalcPortion(ui64 p, ui64 k) {
    int res = p / k;
    if (p % k)
        ++ res;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, h, k;
    cin >> n >> h >> k;

    ui64 res = 0;
    ui64 curh = 0;
    for (int i = 0; i < n; ++i) {
        int ai = 0;
        cin >> ai;

        if ((curh + ai) > h) {
            res += (curh / k);
            curh = curh % k;
            if ((curh + ai) > h) {
                res += 1;
                curh = 0;
            } else {
                curh += ai;
            }
        } else {
            curh += ai;
            res += (curh / k);
            curh = curh % k;
        }

        cout << "\tres=" << res << "\tcurh=" << curh << "\tai=" << ai << endl;
    }

    res += (curh / k);
    res += (curh % k);

    cout << res << endl;
    return 0;
}
