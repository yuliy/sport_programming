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
    int m, d1, d2;
    scanf("%d %d %d", &m, &d1, &d2);

    const int a = (m * d1) / d2;
    const int b = (m * d1) % d2;
    for (int i = 0; i < d2; ++i) {
        if (i < b)
            printf("%d ", a + 1);
        else
            printf("%d ", a);
    }

    return 0;
}
