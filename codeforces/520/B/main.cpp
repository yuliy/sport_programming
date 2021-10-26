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
using TAdj = vector<int>;
using TGraph = vector<TAdj>;

int CalcDistance(int n, int m, int N, const TGraph& g) {
    //cout << "n=" << n << " m=" << m << " N=" << N << endl;
    vector<int> discovered(N+1);
    vector<int> distance(N+1);
    deque<int> q;
    q.push_back(n);
    discovered[n] = 1;
    while (false == q.empty()) {
        //cout << "________________________" << endl;
        const int v = q.front();
        //cout << "v: " << v << endl;
        q.pop_front();
        const TAdj& adj = g[v];
        for (const auto u : adj) {
            //cout << "u: " << u << endl;
            if (false == discovered[u]) {
                discovered[u] = 1;
                distance[u] = distance[v] + 1;
                q.push_back(u);

                if (u == m) {
                    return distance[u];
                }
            }
        }
    }

    return -1; // error
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    const int N = 2 * max(n, m) + 1;
    TGraph g(N+1);
    for (int i = 1; i <= N; ++i) {
        g[i].push_back(i-1);
        if (2*i <= N)
            g[i].push_back(2*i);
    }

    cout << CalcDistance(n, m, N, g) << endl;
    return 0;
}
