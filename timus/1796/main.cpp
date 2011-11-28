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
    int k10, k50, k100, k500, k1000, k5000;
    cin >> k10 >> k50 >> k100 >> k500 >> k1000 >> k5000;
    const int sum = k10*10 + k50*50 + k100*100 + k500*500 + k1000*1000 + k5000*5000;
    int minK = 0;
    if (k10)
        minK = 10;
    else if (k50)
        minK = 50;
    else if (k100)
        minK = 100;
    else if (k500)
        minK = 500;
    else if (k1000)
        minK = 1000;
    else if (k5000)
        minK = 5000;

    int price;
    scanf("%d", &price);

    const int minSum = sum - minK;
    const int maxSum = sum;
    const int min = minSum / price + 1;
    const int max = maxSum / price;

    printf("%d\n", max - min + 1);
    for (int i = min; i <= max; ++i)
        printf("%d ", i);
    printf("\n");

    return 0;
}
