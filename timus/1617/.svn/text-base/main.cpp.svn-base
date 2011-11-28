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
    int a[105];
    for (int i = 0; i < 105; ++i)
        a[i] = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++a[tmp-600];
    }

    int res = 0;
    for (int i = 0; i < 105; ++i)
        res += (a[i] / 4);
    printf("%d\n", res);

    return 0;
}
