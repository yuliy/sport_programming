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
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> degrees(N);
    for (int i = 0; i < M; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        --from;
        --to;
        ++degrees[from];
        ++degrees[to];
    }

    int deg1cnt = 0;
    int deg2cnt = 0;
    int degNM1cnt = 0;
    for (vector<int>::const_iterator iter = degrees.begin(); iter != degrees.end(); ++iter) {
        const int d = *iter;
        if (d == 1)
            ++deg1cnt;
        else if (d == 2)
            ++deg2cnt;
        else if (d == (N-1))
            ++degNM1cnt;
    }

    if (deg1cnt == 2 && deg2cnt == (N-2))
        printf("bus topology\n");
    else if (deg2cnt == N)
        printf("ring topology\n");
    else if (deg1cnt == (N-1) && degNM1cnt == 1)
        printf("star topology\n");
    else
        printf("unknown topology\n");

    return 0;
}
