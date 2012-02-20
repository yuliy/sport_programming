#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int N, K;

struct TCompare {
    bool operator()(const pair<int, int> &l, const pair<int, int> &r) const {
        return l.second > r.second;
    }
};

static int Solve(vector< pair<int, int> > &v) {
    std::sort(v.begin(), v.end(), TCompare());

    int res = 0;
    for (int i = 0; i < N; ++i) {
        cout << "(" << v[i].first << "; " << i << ")\t";
        if (v[i].first > i)
            res += (v[i].first - i);
    }

    cout << res << "\t";
    cout << endl;

    return res;
}

int main() {
    scanf("%d %d", &N, &K);

    if (K == 1) {
        cout << K << endl;
        return 0;
    }

    int max = -1;
    int maxRow = 1;
    vector< pair<int, int> > v(N);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            int tmp;
            scanf("%d", &tmp);
            v[j] = make_pair(j, tmp);
        }

        const int cur = Solve(v);
        if (cur > max) {
            max = cur;
            maxRow = i + 1;
        }
    }

    cout << maxRow << endl;

    return 0;
}
