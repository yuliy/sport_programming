#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int N;
const int BUF_SIZE = 250000 * 3 / 4 + 2;
unsigned int v[BUF_SIZE];

int main() {
    int N;
    scanf("%d\n", &N);

    if (N <= BUF_SIZE) {
        for (int i = 0; i < N; ++i)
            scanf("%ud", v + i);
        sort(v, v + N);
    } else {
        int num = 0;
        for (int i = 0; i < BUF_SIZE; ++i, ++num)
            scanf("%ud", v + i);
        sort(v, v + BUF_SIZE);

        for (int i = N/2 + 2; num < N; ++i, ++num)
            scanf("%ud", v + i);
        sort(v, v + BUF_SIZE);
    }

    double res = 0.0;
    if (N % 2 == 0) {
        res = v[N/2 - 1] + v[N/2];
        res /= 2;
    } else {
        res = v[N/2];
    }
    printf("%.1f\n", res);

    return 0;
}
