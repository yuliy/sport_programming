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

using i64 = long long;

int main() {
    i64 N, K;
    cin >> N >> K;

    i64 sum = 0;
    for (i64 i = 0; i < K ; ++i) {
        i64 tmp = 0;
        cin >> tmp;
        sum += tmp;
    }

    i64 res = sum - (K-1) * N;
    if (res < 0)
        res = 0;

    cout << res << endl;
    return 0;
}
