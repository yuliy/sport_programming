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

/*
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
        auto largest = --m.end();
        const int val = largest->first;
        const int cnt = largest->second;
        if (4 == val || 3 == val) {
            res += 3;
            break;
        }
        if (2 == val) {
            res += 2;
            break;
        }
        if (1 == val) {
            res += 1;
            break;
        }

        const int a = val / 2;
        const int b = val - a;
        m.erase(largest);
        m[a] += cnt;
        m[b] += cnt;
        res += cnt;
    }

    return res;
}
*/

static int SolveSingleCase() {
    int D = 0;
    scanf("%d", &D);

    vector<int> p(D);
    for (int i = 0; i < D; ++i) {
        scanf("%d", &p[i]);
    }

    int res =0;
    for (;;) {
        sort(p.begin(), p.end());
        const int val = p.back();
        if (val <= 3) {
            res += val;
            break;
        }

        const int a = val / 2;
        const int b = val - a;
        p.back() = a;
        p.push_back(b);
        res += 1;
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
