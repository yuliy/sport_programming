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
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, l;
        scanf("%d %d", &n, &l);
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &(a[i]));
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &(b[i]));
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int g_sum = 0;
        int d_sum = 0;
        for (int i = 0; i < l; ++i) {
            g_sum += a[i];
            d_sum += b[n - 1 - i];
        }

        if (g_sum > d_sum) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
