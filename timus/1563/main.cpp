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
    scanf("%d\n", &N);

    set<string> m;
    string line;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        if (m.find(line) == m.end()) {
            m.insert(line);
        } else {
            ++res;
        }
    }

    printf("%d\n", res);
    return 0;
}
