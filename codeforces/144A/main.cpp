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
    for (int i = 0; i < n; ++i)
        scanf("%d", &(a[i]));

    int max = a[0];
    int maxPos = 0;
    int min = a[0];
    int minPos = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
            maxPos = i;
        }

        if (a[i] <= min) {
            min = a[i];
            minPos = i;
        }
    }

    int res = maxPos + (n - minPos - 1);
    if (maxPos > minPos)
        --res;

    printf("%d\n", res);
    return 0;
}
