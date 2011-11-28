#include <stdio.h>
#include <math.h>

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

    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    const size_t cnt = v.size();
    double res = v[cnt-1];
    for (int i = cnt-2; i >= 0; --i) {
        res = 2 * sqrt(res * v[i]);
    }

    printf("%.2f\n", res);

    return 0;
}
