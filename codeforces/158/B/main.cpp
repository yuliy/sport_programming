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
    int n;
    scanf("%d", &n);

    int c[5] = {0};

    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++c[tmp];
    }

    int res = 0;
    for (;;) {
        int tmp = 0;
        for (int i = 4; i >= 1; --i) {
            while (c[i] && ((tmp + i) <= 4)) {
                tmp += i;
                --c[i];
                //cout << i << endl;
            }

            if (tmp == 4)
                break;
        }

        //cout << "Adding. tmp=" << tmp << endl;
        ++res;

        if (c[1] || c[2] || c[3] || c[4])
            continue;
        break;
    }

    printf("%d\n", res);

    return 0;
}
