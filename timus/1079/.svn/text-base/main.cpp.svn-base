#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int a[100005];

static void Init() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= 100000; ++i) {
        if (i % 2 == 0) {
            a[i] = a[i/2];
        } else {
            a[i] = a[i/2] + a[i/2 + 1];
        }
    }
}

int main() {
    Init();

    for (;;) {
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;

        int res = a[0];
        for (int i = 0; i <= num; ++i)
            if (a[i] > res)
                res = a[i];
        printf("%d\n", res);
    }

    return 0;
}
