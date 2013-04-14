#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

bool mat[101][101];
bool done[101] = { false };

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mat[i][j] = false;

    for (int i = 0; i < m; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        mat[from][to] = mat[to][from] = true;
    }

    int res = 0;
    for (;;) {
        int curRes = 0;
        for (int i = 1; i <= n; ++i) {
            if (done[i])
                continue;

            int connectedCnt = 0;
            int connectedIdx = -1;
            for (int j = 1; j <= n; ++j) {
                if (i == j)
                    continue;
                if (done[j])
                    continue;

                if (mat[i][j]) {
                    ++connectedCnt;
                    connectedIdx = j;
                }
            }

            if (connectedCnt == 1) {
                ++curRes;
                done[i] = true;
                done[connectedIdx] = true;
            }
        }

        res += curRes;
        if (curRes == 0)
            break;
    }
    printf("%d\n", res);
    return 0;
}
