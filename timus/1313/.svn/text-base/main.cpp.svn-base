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
    int a[105][105];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &a[i][j]);

    for (int k = 0; k < N; ++k) {
        for (int m = 0; m <= k; ++m) {
            const int i = k - m;
            const int j = m;
            printf("%d ", a[i][j]);
        }
    }

    for (int k = N-2; k >= 0; --k) {
        for (int m = 0; m <= k; ++m) {
            const int i = N-1-m;
            const int j = N-k+m-1;
            printf("%d ", a[i][j]);
        }
    }

    return 0;
}
