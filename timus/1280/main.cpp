#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    scanf("%d %d", &N, &M);
    vector< pair<int, int> > edges;
    for (int i = 0; i < M; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges.push_back( make_pair(from, to) );
    }

    vector<int> ps(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ps[tmp] = i;
    }

    for (vector< pair<int, int> >::const_iterator iter = edges.begin(), end = edges.end(); iter != end; ++iter) {
        const int from = iter->first;
        const int to = iter->second;

        if (ps[from] > ps[to]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
