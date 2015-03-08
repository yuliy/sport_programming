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

    for (char *c = buf; *c; ++c) {
        if (strchr("AOYEUIaoyeui", *c))
            continue;

        if (int(*c) < 97)
            *c += 32;

        printf(".%c", *c);
    }

    printf("\n");

    return 0;
}
