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
    int N, M;
    scanf("%d %d", &N, &M);

    const double mult = 1.0 * (M - 1) / (N - 1);
    const double epsilon = 1e-6;

    double prevY = 0;
    int res = 0;
    for (double x = 1; x < N; ++x) {
        const double nextY = mult * x;
        const int py = floor(prevY);
        const int ny = floor(nextY);
        res += (ny - py);
        if ((nextY - ny) > epsilon)
            ++res;

        prevY = nextY;
    }

    cout << res << endl;
    return 0;
}
