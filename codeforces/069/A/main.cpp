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

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        int dx, dy, dz;
        scanf("%d %d %d", &dx, &dy, &dz);

        x += dx;
        y += dy;
        z += dz;
    }

    if (x == 0 && y == 0 && z == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
