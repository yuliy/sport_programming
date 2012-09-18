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

int gcd(int a, int b) {
    while (a && b) {
        if (a < b)
            b = b % a;
        else
            a = a % b;
    }

    return a + b;
}

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int res = 0;
    for (;;) {
        if (res == 0) {
            res = 1;
            const int tmp = gcd(a, n);
            if (tmp <= n)
                n -= tmp;
            else
                break;
        } else {
            res = 0;
            const int tmp = gcd(b, n);
            if (tmp <= n)
                n -= tmp;
            else
                break;
        }
    }

    printf("%d\n", res);

    return 0;
}
