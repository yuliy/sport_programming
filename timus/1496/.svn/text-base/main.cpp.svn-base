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

    map<string, int> m;
    for (int i = 0; i < N; ++i) {
        char buf[32];
        scanf("%s", buf);
        ++m[buf];
    }

    for (map<string, int>::const_iterator iter = m.begin(), end = m.end(); iter != end; ++iter) {
        if (iter->second > 1)
            printf("%s\n", iter->first.c_str());
    }

    return 0;
}
