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
    int d, sumTime;
    scanf("%d %d", &d, &sumTime);
    vector<int> minTimes(d);
    vector<int> maxTimes(d);
    int minSum = 0;
    int maxSum = 0;
    for (int i = 0; i < d; ++i) {
        scanf("%d %d", &minTimes[i], &maxTimes[i]);
        minSum += minTimes[i];
        maxSum += maxTimes[i];
    }

    if (minSum > sumTime || sumTime > maxSum) {
        cout << "NO" << endl;
        return 0;
    }

    sumTime -= minSum;
    vector<int> res(minTimes);
    for (int i = 0; i < d; ++i) {
        const int diff = maxTimes[i] - minTimes[i];
        if (diff > sumTime) {
            res[i] += sumTime;
            break;
        }

        res[i] += diff;
        sumTime -= diff;
    }

    cout << "YES" << endl;
    for (int i = 0; i < d; ++i)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
