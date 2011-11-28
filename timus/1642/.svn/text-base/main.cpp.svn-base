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
    int n, x;
    scanf("%d %d", &n, &x);

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());

    const int UNDEFINED = -1000000;
    int l = -UNDEFINED, r = -UNDEFINED;
    for (int i = 0; i < (n-1); ++i) {
        if (a[i] < x && x < a[i+1]) {
            if (a[i] < 0 && 0 < a[i+1]) {
                l = a[i];
                r = a[i+1];
            }
        }
    }

    if (a[0] > 0 && x < a[0]) {
        int resb = -x;
        int resf = a[0];
        printf("%d %d\n", resb, resf);
        return 0;
    }

    if (a[n-1] < 0 && x > a[n-1]) {
        int resb = x - 2*a[n-1];
        int resf = -x;
        printf("%d %d\n", resb, resf);
        return 0;
    }

    if (l == -UNDEFINED) {
        printf("Impossible\n");
        return 0;
    }

    int resb = 0, resf = 0;
    if (x > 0) {
        resb = x;
        resf = 2 * r - x;
    } else if (x < 0) {
        resb = x - 2 * l;
        resf = -x;
    } else {
        resb = - 2 * l;
        resf = 2 * r;
    }
    printf("%d %d\n", resb, resf);

    return 0;
}
