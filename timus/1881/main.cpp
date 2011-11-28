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
    int h, w, n;
    scanf("%d %d %d\n", &h, &w, &n);

    int resh = 0;
    int resw = 0;

    char buf[256];
    for (int i = 0; i < n; ++i) {
        //scanf("%s", buf);
        gets(buf);
        const int len = strlen(buf);
        if ((resw + len) >= w)
            ++resh;

        if ((resw + len) <= w) {
            resw += len;
        } else {
            resw = len;
        }
        ++resw;

        //cout << resh << "\t" << resw << endl;
    }

    if (resw > 1)
        ++resh;

    int res = resh / h;
    if (resh % h)
        ++res;

    printf("%d\n", res);
    return 0;
}
