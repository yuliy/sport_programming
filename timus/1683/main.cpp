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
    int N;
    scanf("%d", &N);

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    int n = N;
    int res = 0;
    vector<int> steps;
    for (;;) {
        ++res;
        int nextn = 0;
        if (n % 2)
            ++nextn;
        const int step = n / 2;
        steps.push_back(step);
        nextn += step;
        n = nextn;
        if (n == 1)
            break;
    }

    printf("%d\n", res);
    for (vector<int>::const_iterator iter = steps.begin(), end = steps.end(); iter != end; ++iter) {
        printf("%d ", *iter);
    }
    printf("\n");

    return 0;
}
