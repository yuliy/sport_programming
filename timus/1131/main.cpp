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
    int N, K;
    scanf("%d %d", &N, &K);

    int res = 0;
    int n = 1;
    for (; n < K && n < N;) {
        n <<= 1;
        ++res;
    }

    if (n < N) {
        n = N - n;
        res += (n / K);
        if (n % K)
            ++res;
    }

    printf("%d", res);

    return 0;
}
