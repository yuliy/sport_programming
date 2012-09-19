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
    char buf[128];
    scanf("%s", buf);

    bool res = false;
    for (const char *c = buf; *c; ++c) {
        if (strchr("HQ9", *c)) {
            res = true;
            break;
        }
    }

    printf(res ? "YES\n" : "NO\n");
    return 0;
}
