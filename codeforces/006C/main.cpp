#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    const int totalSum = accumulate(a.begin(), a.end(), 0);

    /*
    const double half = totalSum / 2.0;
    double sum = 0;
    int alisaCount = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ++alisaCount;
        if (sum >= half)
            break;
    }
    */

    printf("%d %d\n", alisaCount, n - alisaCount);
    return 0;
}
