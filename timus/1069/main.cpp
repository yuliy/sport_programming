#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef vector<int> TVertices;
//typedef map<int, int> TVertex2Count;
//typedef priority_queue<int> TQueue;
typedef priority_queue<int, vector<int>, greater<int> > TQueue;

typedef set<int> TAdjList;
typedef vector< TAdjList > TAdjLists;

int main() {
    TVertices vertices;
    //TVertex2Count v2c;
    int v2c[8000] = {0};
    int tmp;
    int N = 0;
    while (scanf("%d", &tmp) != EOF) {
        vertices.push_back(tmp);
        ++v2c[tmp];
        if (tmp > N)
            N = tmp;
    }

    //greater<int> cmp;
    TQueue q;
    //for (TVertex2Count::const_iterator iter = v2c.begin(), end = v2c.end(); iter != end; ++iter)
    for (int i = 1; i <= N; ++i)
        if (v2c[i] == 0)
            q.push(i);

    TAdjLists adjLists(N);

    for (TVertices::const_iterator iter = vertices.begin(), end = vertices.end(); iter != end; ++iter) {
        const int v = *iter;
        if (q.empty())
            continue;

        const int minv = q.top();

        adjLists[minv-1].insert(v);
        adjLists[v-1].insert(minv);

        if (v2c[v] == 0)
            q.push(v);
        else
            --v2c[v];
    }

    for (int i = 0; i < N; ++i) {
        printf("%d:", i + 1);
        const TAdjList &lst = adjLists[i];
        for (TAdjList::const_iterator iter = lst.begin(), end = lst.end(); iter != end; ++iter)
            printf(" %d", *iter);
        printf("\n");
    }

    return 0;
}