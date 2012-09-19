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
    int k, l, m, n, d;
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);

    bool a[100001] = {false};

    for (int i = k; i <= d; i += k)
        a[i] = true;
    for (int i = l; i <= d; i += l)
        a[i] = true;
    for (int i = m; i <= d; i += m)
        a[i] = true;
    for (int i = n; i <= d; i += n)
        a[i] = true;

    int res = 0;
    for (int i = 1; i <= d; ++i)
        if (a[i])
            ++res;

    printf("%d\n", res);
    return 0;
}
