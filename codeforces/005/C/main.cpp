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

const int MAX_SIZE = 10 * 1000 * 1000 + 1;

char buf[MAX_SIZE];

int main() {
    scanf("%s", buf);
    const int len = strlen(buf);

    int lcnt = 0;
    int rcnt = 0;
    int maxLen = 0;
    int maxCnt = 1;
    for (int i = 0; i < len; ++i) {
        const char ch = buf[i];
        if (ch == '(')
            ++lcnt;
        else
            ++rcnt;

        if (lcnt < rcnt) {
            lcnt = 0;
            rcnt = 0;
        }

        const int curLen = 2 * rcnt;
        if (curLen > maxLen) {
            maxLen = curLen;
            maxCnt = 1;
        } else if (lcnt == rcnt && curLen == maxLen) {
            ++maxCnt;
        }

        cout << "=== i=" << i << " =============" << endl;
        cout << "lcnt=" << lcnt << endl
            << "rcnt=" << rcnt << endl
            << "curLen=" << curLen << endl
            << "maxLen=" << maxLen << endl
            << "maxCnt=" << maxCnt << endl
            << endl;
    }

    if (maxLen == 0)
        maxCnt = 1;

    printf("%d %d\n", maxLen, maxCnt);
    return 0;
}
