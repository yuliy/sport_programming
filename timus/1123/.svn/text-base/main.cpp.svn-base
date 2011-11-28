#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static void Fix(char *beg, char* end) {
    if (beg >= end)
        return;

    --end;
    ++(*end);
    for (; beg <= end;) {
        if (*end <= '9')
            break;
        *end = '0';
        --end;
        ++(*end);
    }
}

int main() {
    const size_t MAX_SIZE = 2048;
    char buf[MAX_SIZE];
    scanf("%s", buf);
    const size_t len = strlen(buf);

    char *beg = buf;
    char *end = buf + len - 1;
    for (; beg < end; ++beg, --end) {
        char &a = *beg;
        char &b = *end;

        if (a > b)
            b = a;
        else if (a < b) {
            b = a;
            Fix(buf, end);
            beg = buf -1 ;
            end = buf + len - 1 + 1;
        }
    }

    printf("%s\n", buf);
    return 0;
}
