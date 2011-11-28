#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

bool CheckPalindrome(const char *beg, const char *end) {
    for (; beg < end; ++beg, --end) {
        if (*beg != *end)
            return false;
    }
    return true;
}

int main() {
    char buf[1024];
    scanf("%s", buf);

    const int len = strlen(buf);
    //const char *beg = buf;
    //const char *end = buf + len - 1;

    int resLen = 0;
    int resPos = -1;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            const char *b = buf + i;
            const char *e = buf + j;
            if (CheckPalindrome(buf + i, buf + j)) {
                const int curLen = e - b + 1;
                if (curLen > resLen) {
                    resLen = curLen;
                    resPos = i;
                } else if (curLen == resLen) {
                    if (i < resPos)
                        resPos = i;
                }
            }
        }
    }

    char s[1024];
    for (int i = 0; i < resLen; ++i) {
        s[i] = buf[resPos + i];
    }
    s[resLen] = 0;
    printf("%s\n", s);
    return 0;
}
