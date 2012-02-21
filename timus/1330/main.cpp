#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const int MAX_N = 10000;
int mass[MAX_N];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", mass + i);
    for (int i = 1; i < N; ++i)
        mass[i] += mass[i-1];

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        int res = mass[b-1];
        if (a > 0)
            res -= mass[a-2];
        printf("%d\n", res);
    }

    return 0;
}
