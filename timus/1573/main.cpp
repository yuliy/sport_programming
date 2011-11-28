#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int B, R, Y;
    scanf("%d %d %d", &B, &R, &Y);

    int K;
    scanf("%d", &K);
    bool fb = false, fr = false, fy = false;
    for (int i = 0; i < 3; ++i) {
        char buf[32];
        scanf("%s", buf);
        if (strcmp(buf, "Blue") == 0)
            fb = true;
        if (strcmp(buf, "Red") == 0)
            fr = true;
        if (strcmp(buf, "Yellow") == 0)
            fy = true;
    }

    const int res = (fb ? B : 1) * (fr ? R : 1) * (fy ? Y : 1);
    printf("%d\n", res);

    return 0;
}
