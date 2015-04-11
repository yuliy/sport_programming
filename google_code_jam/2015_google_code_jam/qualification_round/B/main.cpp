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

static const bool DBG = false;

void Print(const vector<int>& v) {
    cout << "p[]: ";
    for (auto elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

int FindMax(const vector<int>& v) {
    int res = v.front();
    for (auto elem : v) {
        if (elem > res)
            res = elem;
    }
    return res;
}

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
        if (val <= 3) {
            res += val;
            break;
        }

        const int a = val / 2;
        const int b = val - a;
        if ( (cnt + max(a, b)) < val) {
            m.erase(largest);
            m[a] += cnt;
            m[b] += cnt;
            res += cnt;
        } else {
            res += val;
            break;
        }
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
