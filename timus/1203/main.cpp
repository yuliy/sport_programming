#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

struct TCompare {
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const {
        return lhs.second < rhs.second;
    }
};

int main() {
    int N;
    scanf("%d", &N);

    vector< pair<int, int> > ps;
    for (int i = 0; i < N; ++i) {
        int b, e;
        scanf("%d %d", &b, &e);
        ps.push_back(make_pair(b, e));
    }

    sort(ps.begin(), ps.end(), TCompare());

    int res = 0;
    int last = 0;
    for (vector< pair<int, int> >::const_iterator iter = ps.begin(), end = ps.end(); iter != end; ++iter) {
        const int b = iter->first;
        const int e = iter->second;

        if (b > last) {
            last = e;
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
