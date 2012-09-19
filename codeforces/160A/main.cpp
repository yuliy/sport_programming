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

    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        total += tmp;
        a[i] = tmp;
    }

    sort(a.begin(), a.end());
    int res = 0;
    int sum = 0;
    for (int i = n-1; i >= 0; --i) {
        sum += a[i];
        ++res;
        if (sum > (total-sum))
            break;
    }

    printf("%d\n", res);
    return 0;
}
