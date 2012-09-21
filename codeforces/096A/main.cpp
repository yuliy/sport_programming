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

bool Check(const char *s) {
    int cnt = 0;
    char prev = '1';
    for (; *s; ++s) {
        if (prev != *s) {
            cnt = 1;
            prev = *s;
        } else
            ++cnt;

        if (cnt >= 7)
            return true;
    }

    if (cnt >= 7)
        return true;
    return false;
}

int main() {
    char buf[128];
    scanf("%s", buf);

    if (Check(buf))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
