#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const int MAX_FIB_NUM = 50;
long long F[MAX_FIB_NUM+2];

static void Init() {
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i <= MAX_FIB_NUM; ++i)
        F[i] = F[i-1] + F[i-2];
}

int main() {
    Init();

    long long N, K;
    scanf("%lld %lld", &N, &K);
    --K;

    int res[MAX_FIB_NUM];
    for (int i = N; i > 0; --i)
        res[i] = 0;

    for (int i = N; i > 0; ) {
        if (K >= F[i]) {
            K -= F[i];
            res[i] = 1;
            i -= 2;
        } else {
            --i;
        }
    }

    if (K == 0) {
        for (int i = N; i > 0; --i)
            cout << res[i];
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
