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
    int n, k;
    scanf("%d %d", &n, &k);

    int expected_sum = k - 2;
    int cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        int b, g;
        scanf("%d %d", &b, &g);
        expected_sum += (b-2);
        cur_sum += g;
    }

    const int res = expected_sum - cur_sum;
    if (res < 0)
        printf("Big Bang!");
    else
        printf("%d\n", res);
    return 0;
}
