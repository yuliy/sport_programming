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
    const int MAX_SIZE = 10 * 1000 * 1000 + 1;
    char buf[MAX_SIZE];
    scanf("%s", buf);
    const int len = strlen(buf);

    int lcnt = 0;
    int rcnt = 0;
    int curLen = 0;
    int maxLen = 0;
    int maxCnt = 1;
    for (int i = 0; i < len; ++i) {
        const char ch = buf[i];
        if (ch == '(')
            ++lcnt;
        else
            ++rcnt;

        if (lcnt >= rcnt)
            ++curLen;
        else
            curLen = 0;

        if (lcnt == rcnt) {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxCnt = 1;
            } else if (curLen == maxCnt) {
                ++maxCnt;
            }
        }
    }

    printf("%d %d\n", maxLen, maxCnt);
    return 0;
}
