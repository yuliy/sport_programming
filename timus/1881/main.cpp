#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int h, w, n;
    scanf("%d %d %d\n", &h, &w, &n);

    int resh = 0;
    int resw = 0;

    for (int i = 0; i < n; ++i) {
        char buf[256];
        scanf("%s", buf);
        //gets(buf);
        const int len = strlen(buf);

        if ((resw + len) <= w) {
            resw += len;
        } else {
            ++resh;
            resw = len;
        }

        if (resw == w) {
            ++resh;
            resw = 0;
        } else {
            ++resw;
        }
    }

    if (resw > 0)
        ++resh;

    int res = resh / h;
    if (resh % h)
        ++res;

    printf("%d\n", res);
    return 0;
}
