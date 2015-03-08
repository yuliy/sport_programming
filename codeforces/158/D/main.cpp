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
    int n;
    scanf("%d", &n);

    vector<int> t(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &(t[i]));

    int res = -1000 * 1000 * 1000;
    const int maxd = n / 2;
    for (int d = 1; d <= maxd; ++d) {
        if (n % d)
            continue;

        if ((n / d) < 3)
            continue;

        for (int offset = 0; offset < d; ++offset) {
            int sum = 0;
            for (int i = offset; i < n; i += d)
                sum += t[i];

            //cout << "d=" << d << "\toffset=" << offset << "\tsum=" << sum << endl;
            if (sum > res)
                res = sum;
        }
    }

    printf("%d\n", res);
    return 0;
}
