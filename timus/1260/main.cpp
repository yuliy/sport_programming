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
    int s[60];
    s[1] = 1;
    s[2] = 1;
    s[3] = 2;
    s[4] = 4;
    s[5] = 6;
    s[6] = 9;
    s[7] = 14;

    int N;
    scanf("%d", &N);
    for (int i = 7; i <= N; ++i)
        s[i] = s[i-1] + s[i-2] - s[i-5];

    printf("%d\n", s[N]);
    return 0;
}
