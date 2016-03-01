#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int sum = 0;
    int maxSum = 0;

    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);
        sum += tmp;
        if (sum < 0)
            sum = 0;
        maxSum = max(sum, maxSum);
    }

    printf("%d\n", maxSum);
    return 0;
}
