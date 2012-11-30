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
    int n, t, s;
    scanf("%d %d %d", &n, &t, &s);

    for (int i = 0; i < n; ++i) {
        int si;
        scanf("%d", &si);
        const double diff = abs(s - si);
        if (s < si) {
            const double res = si + (t - diff)/2.0;
            printf("%.6f\n", res);
        } else {
            const double res = s + (t - diff)/2.0;
            printf("%.6f\n", res);
        }
    }
    return 0;
}
