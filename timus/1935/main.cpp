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
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    int res = v[0] + v[n-1];
    for (int i = 1; i < n; ++i) {
        res += max(v[i-1], v[i]);
    }
    printf("%d\n", res);
    return 0;
}
