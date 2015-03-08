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

void PrintLine(int n, int i) {
    const int spaces = n - i;
    for (int j = 0; j < spaces; ++j)
        printf("  ");

    if (i == 0)
        printf("0");
    else {
        for (int j = 0; j <= i; ++j)
            printf("%d ", j);
    }

    for (int j = i-1; j >= 0; --j)
        if (j > 0)
            printf("%d ", j);
        else
            printf("%d", j);

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; ++i)
        PrintLine(n, i);

    for (int i = n-1; i >= 0; --i)
        PrintLine(n, i);

    return 0;
}
