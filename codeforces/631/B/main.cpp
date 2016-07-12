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

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector< pair<int, int> > R(n);
    vector< pair<int, int> > C(m);
    for (int timer = 0; timer < k; ++timer) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int ri, ai;
            scanf("%d %d", &ri, &ai);
            --ri;
            R[ri] = make_pair(ai, timer);
        } else {
            int ci, ai;
            scanf("%d %d", &ci, &ai);
            --ci;
            C[ci] = make_pair(ci, timer);
        }
    }

    for (int ri = 0; ri < n; ++ri) {
        for (int ci = 0; ci < m; ++ci) {
            const int colour = (R[ri].second > C[ci].second)
                ? R[ri].first
                : C[ci].first;
            printf ("%d ", colour);
        }
        printf("\n");
    }

    return 0;
}
