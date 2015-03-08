#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;

bool IsLucky(int num) {
    while (num) {
        const int d = num % 10;
        if ((d != 4) && (d != 7))
            return false;
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    bool almostLucky = false;
    const int max = n / 2 + 1;
    for (int i = 2; i < max; ++i) {
        if ((n % i == 0) && IsLucky(i)) {
            almostLucky = true;
            break;
        }
    }

    if (almostLucky || IsLucky(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
