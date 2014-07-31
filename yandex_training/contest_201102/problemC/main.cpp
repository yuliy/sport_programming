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

int main() {
    int n;
    cin >> n;
    TAdjLists adjLists(n+1);
    for (int i = 0; i < n; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        adjLists[from].push_back( to );
        adjLists[to].push_back( from );
    }

    PrintGraph(adjLists);

    return 0;
}
