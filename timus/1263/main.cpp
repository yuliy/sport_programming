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
int k[MAX_N];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i)
        k[i] = 0;

    for (int i = 0; i < M; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++k[tmp-1];
    }

    for (int i = 0; i < N; ++i) {
        const double p = 100.0 * k[i] / M;
        printf("%.2f%%\n", p);
    }

    return 0;
}
