#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int ecnt = 0, lcnt = 0, mcnt = 0;
    for (int i = 0; i < N; ++i) {
        char buf[32];
        char buf2[32];
        scanf("%s %s", buf, buf2);
        switch(buf[0]) {
        case 'E': ++ecnt; break;
        case 'L': ++lcnt; break;
        case 'M': ++mcnt; break;
        }
    }

    const int res = max(ecnt, max(lcnt, mcnt));
    if (res == ecnt)
        printf("Emperor Penguin\n");
    else if (res == lcnt)
        printf("Little Penguin\n");
    else if (res == mcnt)
        printf("Macaroni Penguin\n");

    return 0;
}
