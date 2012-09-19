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
    char buf1[256];
    char buf2[256];
    scanf("%s %s", buf1, buf2);

    int res = 0;
    for (char *s1 = buf1, *s2 = buf2; *s1 && *s2; ++s1, ++s2) {
        if (*s1 < 97)
            *s1 += 32;
        if (*s2 < 97)
            *s2 += 32;

        if (*s1 < *s2) {
            res = -1;
            break;
        }

        if (*s1 > *s2) {
            res = 1;
            break;
        }
    }

    printf("%d\n", res);
    return 0;
}
