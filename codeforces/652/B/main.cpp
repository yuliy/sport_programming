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
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i = 0 ; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    int pos = 0;
    vector<int> res(N);
    for (int i = 0; i < N; i += 2) {
        res[i] = a[pos++];
    }
    for (int i = N-1; i >= 0; --i) {
        if (i & 1)
            res[i] = a[pos++];
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
