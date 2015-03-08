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

bool CheckCase(const char *s) {
    if (!s || !*s)
        return true;

    for (++s; *s; ++s) {
        if (*s > 90)
            return true;
    }

    return false;
}

int main() {
    char buf[128];
    scanf("%s", buf);

    if (!CheckCase(buf)) {
        for (char *s = buf; *s; ++s) {
            if (*s < 97)
                *s += 32;
            else
                *s -= 32;
        }
    }

    printf("%s\n", buf);
    return 0;
}
