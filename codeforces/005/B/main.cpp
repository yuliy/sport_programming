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
    vector<string> lines;
    char buf[1024];
    int maxLen = 0;
    while (gets(buf)) {
        lines.push_back(buf);
        const int curLen = strlen(buf);
        if (curLen > maxLen)
            maxLen = curLen;
    }

    //
    for (int i = 0; i < (maxLen+2); ++i)
        buf[i] = '*';
    buf[maxLen+2] = 0;
    printf("%s\n", buf);

    bool alignToLeft = true;
    for (vector<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter) {
        const string &line = *iter;
        const int len = line.length();
        const int spacesCnt = maxLen - len;
        printf("*");
        const int spCnt = spacesCnt / 2;
        for (int i = 0; i < spCnt; ++i)
            buf[i] = ' ';
        buf[spCnt] = 0;
        printf("%s", buf);

        if (spacesCnt % 2 == 0) {
            printf("%s", line.c_str());
        } else {
            if (!alignToLeft)
                printf(" ");
            printf("%s", line.c_str());
            if (alignToLeft)
                printf(" ");
            alignToLeft = !alignToLeft;
        }

        printf("%s", buf);
        printf("*\n");
    }

    //
    for (int i = 0; i < (maxLen+2); ++i)
        buf[i] = '*';
    buf[maxLen+2] = 0;
    printf("%s\n", buf);
    return 0;
}
