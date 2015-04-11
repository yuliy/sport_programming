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

static int SolveSingleCase() {
    int smax = 0;
    char buf[1024];
    scanf("%d %s", &smax, buf);

    int cnt = buf[0] - '0';
    int res = 0;
    for (int i = 1; i <= smax; ++i) {
        const int si = buf[i] - '0';
        if (cnt < i) {
            res += (i - cnt);
            cnt = i;
        }
        cnt += si;
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
