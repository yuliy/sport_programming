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
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }

    const int g = a[k-1];
    int res = 0;
    for (int i = 0; i < n; ++i)
        if ((a[i] >= g) && a[i])
            ++res;

    printf("%d\n", res);
    return 0;
}
