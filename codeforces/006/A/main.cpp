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

static const char *solve(const vector<int> &a) {
    if ((a[0] + a[1]) > a[2])
        return "TRIANGLE";

    if ((a[1] + a[2]) > a[3])
        return "TRIANGLE";

    if ((a[0] + a[1]) == a[2])
        return "SEGMENT";

    if ((a[1] + a[2]) == a[3])
        return "SEGMENT";

    return "IMPOSSIBLE";
}

int main() {
    vector<int> a(4);
    for (int i = 0; i < 4; ++i)
        scanf("%d", &a[i]);

    sort(a.begin(), a.end());

    printf("%s\n", solve(a));
    return 0;
}
