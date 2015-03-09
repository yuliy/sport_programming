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

struct TCmp {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.first < rhs.first;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    vector<int> w(n);
    vector< pair<int, int> > h2idx(n);
    int wsum = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &w[i], &(h2idx[i].first));
        h2idx[i].second = i;
        wsum += w[i];
    }

    sort(h2idx.begin(), h2idx.end(), TCmp());

    const int max1 = h2idx[n-1].first;
    const int max2 = h2idx[n-2].first;
    const int max1idx = h2idx[n-1].second;
    //const int max2idx = h2idx[n-2].second;

    for (int i = 0; i < n; ++i) {
        const int W = wsum - w[i];
        const int H = (i == max1idx) ? max2 : max1;
        const long long res = W * H;
        printf("%I64d ", res);
    }

    return 0;
}
