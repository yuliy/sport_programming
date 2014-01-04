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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int total = accumulate(a.begin(), a.end(), 0);
    bool movingRight = true;
    for (int pos = 1; total; ) {
        if (a[pos-1]) {
            --a[pos-1];
            printf("P");
            --total;
        }

        if (movingRight) {
            if (pos == n) {
                --pos;
                printf("L");
                movingRight = false;
            } else {
                ++pos;
                printf("R");
            }
        } else {
            if (pos == 0) {
                ++pos;
                printf("R");
                movingRight = true;
            } else {
                --pos;
                printf("L");
            }
        }
    }

    return 0;
}
