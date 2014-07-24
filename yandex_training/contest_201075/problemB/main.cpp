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

enum EState {
    ST_NONE,
    ST_IN_SEQUENCE,
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int global_res = 0;
    for (;;) {
        vector<int> newa;
        n = a.size();
        int res = 0;
        int cur_len = 0;
        EState state = ST_NONE;
        for (int i = 1; i < n; ++i) {
            switch(state) {
            case ST_NONE: {
                    if (a[i-1] > a[i]) {
                        state = ST_IN_SEQUENCE;
                        cur_len = 1;
                        newa.push_back(a[i-1]);
                    }
                } break;
            case ST_IN_SEQUENCE: {
                    if (a[i-1] < a[i]) {
                        ++cur_len;
                    } else {
                        res = max(cur_len, res);
                        state = ST_NONE;
                    }
                } break;
            }
        }

        if (state == ST_IN_SEQUENCE) {
            res = max(cur_len, res);
        }

        if (newa.size() == a.size())
            break;

        global_res += res;
        a.swap(newa);
        cout << res << endl;
    }

    cout << global_res << endl;
    return 0;
}
