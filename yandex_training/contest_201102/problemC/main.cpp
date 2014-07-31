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

typedef vector< pair<int, int> > TAdjList;
typedef vector< TAdjList > TAdjLists;

static void PrintGraph(const TAdjLists &g) {
    #ifdef DEBUG
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
    #endif
}

int main() {
    int n;
    cin >> n;
    TAdjLists adjLists(n+1);
    for (int i = 0; i < n; ++i) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        adjLists[from].push_back( make_pair(to, cost) );
        if (from != 1 | adjLists[from].size() > 1)
            adjLists[to].push_back( make_pair(from, -cost) );
    }

    PrintGraph(adjLists);

    return 0;
}
