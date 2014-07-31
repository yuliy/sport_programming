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

#define DEBUG

typedef vector<int> TAdjList;
typedef vector< TAdjList > TAdjLists;

static void PrintGraph(const TAdjLists &g) {
    #ifdef DEBUG
    const int n = g.size() - 1;
    for (int from = 1; from <= n; ++from) {
        cout << from << ": ";
        const TAdjList &lst = g[from];
        for (TAdjList::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
            const int to = *iter;
            cout << to << " ";
        }
        cout << endl;
    }
    #endif
}

static void DFS_Visit(const TAdjLists &g, vector<bool> &visited, int u) {
    visited[u] = true;
    cout << u << endl;
    const TAdjList &lst = g[u];
    for (TAdjList::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        const int v = *iter;
        if (!visited[v]) {
            DFS_Visit(g, visited, v);
        }
    }
}

static void DFS(const TAdjLists &g, vector<bool> &visited) {
    const int n = g.size() - 1;
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            DFS_Visit(g, visited, u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    TAdjLists g(n+1);
    for (int i = 0; i < n; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        g[from].push_back( to );
        g[to].push_back( from );
    }

    PrintGraph(g);

    vector<bool> visited(n + 1);
    DFS(g, visited);
    return 0;
}
