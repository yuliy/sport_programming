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
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    const int start = M % N;
    for (int i = 0; i < 10; ++i) {
        int idx = start + i;
        if (idx >= N)
            idx -= N;
        printf("%d", v[idx]);
    }
    printf("\n");

    return 0;
}
