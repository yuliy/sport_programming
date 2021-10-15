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

using ui64 = unsigned long long;
using i64 = long long;

using TAdjList = vector<int>;
using TGraph = vector<TAdjList>;

int Solve(const TGraph& graph, int n) {

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, k;
        cin >> n >> k;
        TGraph graph(n-1);
        for (int i = 0; i < (n-1); ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << Solve(graph, n) << endl;
    }

    return 0;
}
