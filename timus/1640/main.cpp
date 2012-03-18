#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    double maxr = 0.0;
    for (int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        const double r = sqrt(1.0 * x * x + 1.0 * y * y);
        if (r > maxr)
            maxr = r;
    }

    printf("0 0 %.10f\n", maxr);
    return 0;
}
