#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        cnt -= a;
        cnt += b;
        if (cnt > res)
            res = cnt;
    }

    printf("%d\n", res);
    return 0;
}
