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
        if (DBG) {
            cout << "val=" << val << "\t" << "cnt=" << cnt << endl;
        }
        if (val <= 3) {
            res += val;
            break;
        }
        int prevVal = 0;
        if (m.size() > 1) {
            prevVal = (--(--m.end()))->first;
        }
        const int diff = val - prevVal;

        const int a = val / 2;
        const int b = val - a;
        if (
            ((cnt + max(a, b)) <= val)
            &&
            (diff >= cnt)
        ) {
            if (DBG)
                cout << "splitting..." << endl;
            m.erase(largest);
            m[a] += cnt;
            m[b] += cnt;
            res += cnt;
        } else {
            if (DBG)
                cout << "waiting..." << endl;
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
