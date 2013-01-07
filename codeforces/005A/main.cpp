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
    int usersCount = 0;
    int res = 0;
    char buf[256];
    while(gets(buf)) {
        if (buf[0] == '-') {
            --usersCount;
        } else if (buf[0] == '+') {
            ++usersCount;
        } else {
            const char *delim = strchr(buf, ':');
            const int len = strlen(delim) - 1;
            res += (len * usersCount);
        }
    }

    printf("%d\n", res);
    return 0;
}
