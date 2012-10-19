#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    typedef unordered_map<string, int> TMap;
    TMap name2count;
    for (int i = 0; i < N; ++i) {
        char buf[64];
        scanf("%s", buf);

        TMap::const_iterator iter = name2count.find(buf);
        if (iter == name2count.end()) {
            printf("OK\n");
        } else {
            printf("%s%d\n", buf, iter->second);
        }
        ++name2count[buf];
    }
    return 0;
}
