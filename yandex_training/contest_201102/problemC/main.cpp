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

static bool DFS_Visit(const TAdjLists &g, vector<bool> &visited, int u, vector<int> &cycle) {
    visited[u] = true;
    cycle.push_back(u);
    cout << "(" << u << ")" << endl;
    const TAdjList &lst = g[u];
    for (TAdjList::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        const int v = *iter;
        if (!visited[v]) {
            if (DFS_Visit(g, visited, v, cycle)) {
                return true;
            }
        } else {
            cycle.push_back(v);
            return true;
        }
    }

    cycle.pop_back();
    return false;
}

static void DFS(const TAdjLists &g, vector<bool> &visited, vector<int> &cycle) {
    const int n = g.size() - 1;
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            cycle.clear();
            if (DFS_Visit(g, visited, u, cycle)) {
                return;
            }
        }
    }
    cycle.clear();
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
    vector<int> cycle;
    DFS(g, visited, cycle);
    for (vector<int>::const_iterator iter = cycle.begin(); iter != cycle.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
