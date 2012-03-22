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

int r[100000];

int MergeAndCountInversions(vector<int> &v, int beg, int m, int end) {
    //vector<int> r;
    int inv = 0;
    int i = beg, j = m+1, k = 0;
    while(i <= m && j <= end) {
        if (v[i] <= v[j]) {
            r[k] = v[i];
            ++i;
        } else { 
            r[k] = v[j];
            ++j;
            inv += (m - i + 1);
        }
        ++k;
    }

    for (; i <= m; ++i, ++k)
        r[k] = v[i];
    for (; j <= end; ++j, ++k)
        r[k] = v[j];

    for (int i = 0; i < k; ++i)
        v[beg+i] = r[i];
    return inv;
}

int CalcInversions(vector<int> &v, int beg, int end) {
    if (beg >= end)
        return 0;

    const int m = (beg + end) / 2;
    const int x = CalcInversions(v, beg, m);
    const int y = CalcInversions(v, m+1, end);
    const int z = MergeAndCountInversions(v, beg, m, end);
    return x + y + z;
}
static int Solve(vector<int> &v) {
    return CalcInversions(v, 0, v.size() - 1);
}

int main() {
    scanf("%d %d", &N, &K);

    if (K == 1) {
        cout << K << endl;
        return 0;
    }

    int max = -1;
    int maxRow = 1;
    for (int i = 0; i < K; ++i) {
        vector<int> v(N);
        for (int j = 0; j < N; ++j) {
            int tmp;
            scanf("%d", &tmp);
            v[j] = tmp;
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
