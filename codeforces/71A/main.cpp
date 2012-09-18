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
    int N;
    scanf("%d", &N);

    char buf[128];
    for (int i = 0; i < N; ++i) {
        scanf("%s", buf);
        const int len = strlen(buf);
        if (len <= 10)
            printf("%s\n", buf);
        else
            printf("%c%d%c\n", buf[0], len-2, buf[len-1]);
    }

    return 0;
}
