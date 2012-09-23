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
    char buf1[128];
    char buf2[128];
    scanf("%s %s", buf1, buf2);
    for (char *s1 = buf1, *s2 = buf2; *s1 && *s2; ++s1, ++s2) {
        if (*s1 != *s2)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    return 0;
}
