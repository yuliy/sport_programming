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

void Print(const TGraph& graph) {
    cout << "=== GRAPH: ===" << endl;
    const int n = graph.size();
    for (int i = 0; i < n; ++i) {
        cout << (i+1) << ": ";
        for (const auto v : graph[i]) {
            cout << (v+1) << " ";
        }
        cout << endl;
    }
    cout << "====================" << endl << endl;
}

void Print(const deque<int>& q) {
    cout << "=== QUEUE: ===" << endl;
    for (const auto u : q) {
        cout << (u+1) << " ";
    }
    cout << endl << "===================" << endl << endl;
}

int CalcAdj(const TGraph& graph, const vector<int>& rank, int v) {
    int res = 0;
    const TAdj& adj = graph[v];
    for (const auto w : adj) {
        if (rank[w] == 0)
            ++res;
    }
    return res;
}

int Solve(const TGraph& graph, int n, int k) {
    int result = n;
    vector<int> rank(n);

    deque<int> q;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() <= 1) {
            q.push_back(i);
            rank[i] = 1;
        }
    }
    result -= q.size();
    //Print(q);

    for (int i = 1; i < k; ++i) {
        if (q.empty())
            break;
        //cout << "step: " << i << endl;
        //Print(q);
        deque<int> newq;

        for (const auto u : q) {
            const auto& adj = graph[u];
            for (const auto v : adj) {
                if ((rank[v] == 0) && (CalcAdj(graph, rank, v) <= 1)) {
                    --result;
                    rank[v] = 1;
                    newq.push_back(v);
                }
            }
        }

        newq.swap(q);
    }

    return result;
}

/*
int Solve(const TGraph& graph, int n, int k) {
    int result = n;
    vector<int> rank(n);

    deque<int> q;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() == 1) {
            q.push_back(i);
            rank[i] = 1;
        }
    }
    result -= q.size();

    while (false == q.empty()) {
        const int u = q.front();
        q.pop_front();
        const auto& adj = graph[u];
        for (const auto v : adj) {
            if ((rank[v] == 0) && (CalcAdj(graph, rank, v) == 1)) {
                rank[v] = rank[u] + 1;
                if (rank[v] < k) {
                    q.push_back(v);
                    --result;
                }
            }
        }
    }

    return result;
}
*/

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, k;
        cin >> n >> k;
        TGraph graph(n);
        for (int i = 0; i < (n-1); ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << Solve(graph, n, k) << endl;
    }

    return 0;
}
