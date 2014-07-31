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

typedef vector< pair<int, int> > TAdjList;
typedef vector< TAdjList > TAdjLists;

static void PrintGraph(const TAdjLists &g) {
    const int n = g.size() - 1;
    for (int from = 1; from <= n; ++from) {
        cout << from << ": ";
        const TAdjList &lst = g[from];
        for (TAdjList::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
            const int to = iter->first;
            const int cost = iter->second;
            cout << "(" << to << ", " << cost << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    TAdjLists adjLists(n+1);
    for (int i = 0; i < n; ++i) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        adjLists[from].push_back( make_pair(to, cost) );
        adjLists[to].push_back( make_pair(from, -cost) );
    }

    PrintGraph(adjLists);

    int pc = 0;
    int nc = 0;
    int cur_vertex = 1;
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; ++i) {
        const TAdjList &lst = adjLists[cur_vertex];
        for (TAdjList::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
            const int to_vertex = iter->first;
            const int cost = iter->second;
            if (visited[to_vertex])
                continue;

            if (cost > 0) {
                pc += cost;
            } else {
                nc -= cost;
            }

            cout << cur_vertex << "\t" << to_vertex << "\t" << cost << "\t(pc=" << pc << "; nc=" << nc << ")" << endl;
            visited[to_vertex] = true;
            cur_vertex = to_vertex;
        }
    }

    cout << min(pc, nc) << endl;

    return 0;
}
