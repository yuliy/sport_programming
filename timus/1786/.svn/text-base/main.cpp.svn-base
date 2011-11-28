#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const char name[] = "Sandro";

bool lcase(char ch) {
    return ('a' <= ch) && (ch <= 'z');
}

bool ucase(char ch) {
    return ('A' <= ch) && (ch <= 'Z');
}

static int Calc(const char *p) {
    int res = 0;
    for (int i = 0; i < 6; ++i) {
        char ch = *(p + i);
        char nch = *(name + i);
        if (ch == nch)
            continue;

        res += 5;
        if (lcase(ch) && ucase(nch)) {
            nch += 32;
            if (ch != nch)
                res += 5;
        }

        if (ucase(ch) && lcase(nch)) {
            nch -= 32;
            if (ch != nch)
                res += 5;
        }
    }
    return res;
}

int main() {
    char buf[256];
    scanf("%s", buf);

    const int len = strlen(buf);
    int res = 1000 * 1000;
    for (int i = 0; i < (len-5); ++i) {
        const char *p = buf + i;
        const int curRes = Calc(p);
        if (curRes < res)
            res = curRes;
    }

    printf("%d\n", res);
    return 0;
}
