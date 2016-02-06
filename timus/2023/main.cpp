#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

int GetPos(const char* name) {
    if (strchr("APOR", name[0]))
        return 0;
    if (strchr("BMS", name[0]))
        return 1;
    return 2;
}

int main() {

    int n = 0;
    scanf("%i", &n);

    int res = 0;
    int curPos = 0;
    char buf[256];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        const int nextPos = GetPos(buf);
        res += abs(curPos - nextPos);
        curPos = nextPos;
    }
    printf("%d\n", res);

    return 0;
}
