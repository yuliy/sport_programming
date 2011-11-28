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
    char buf[1024];
    scanf("%s", buf);

    const int cnt = strlen(buf);
    int a[1024];
    for (int i = 0; i < cnt; ++i)
        a[i] = buf[i] - 'a';

    int b[1024];
    b[0] = a[0] - 5;
    while (b[0] < 0)
        b[0] += 26;
    for (int i = 1; i < cnt; ++i) {
        b[i] = a[i] - a[i-1];
        while (b[i] < 0)
            b[i] += 26;
    }

    char res[1024];
    for (int i = 0; i < cnt; ++i) {
        res[i] = b[i] + 'a';
    }
    res[cnt] = 0;
    printf("%s\n", res);

    return 0;
}
