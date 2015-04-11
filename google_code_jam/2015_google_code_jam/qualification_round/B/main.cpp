#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef map<int, int> TMap;

static int SolveSingleCase() {
    int D = 0;
    scanf("%d", &D);

    TMap m;
    for (int i = 0; i < D; ++i) {
        int pi = 0;
        scanf("%d", &pi);
        ++m[pi];
    }

    int res =0;
    for (;;) {

    }

    return res;
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
