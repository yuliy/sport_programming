#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    long long R[MAX_SIZE];
    long long W[MAX_SIZE];

    int N;
    scanf("%d", &N);

    R[0] = W[0] = 0;
    R[1] = W[1] = 1;
    for (int i = 2; i <= N; ++i) {
        R[i] = R[i-1] + R[i-2];
        W[i] = W[i-1] + W[i-2];
    }

    const long long res = R[N] + W[N];
    printf("%lld\n", res);
    return 0;
}
