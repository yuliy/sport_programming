#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int x0, y0, x1, y1;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    int N;
    scanf("%d", &N);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        const int t = (a * x0 + b * y0 + c) * (a * x1 + b * y1 + c);
        if (t < 0)
            ++res;
    }
    cout << res << endl;
    return 0;
}
