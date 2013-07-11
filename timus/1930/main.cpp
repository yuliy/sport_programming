#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

enum EDirection {
    UNDEFINED,
    DOWN,
    UP
};

static const int INF = 1000 * 1000 * 1000;

struct TVertex {
    int Cost;
    EDirection Direction;

    TVertex() : Cost(INF), Direction(UNDEFINED) {}
};

typedef vector<TVertex> TVertices;
typedef vector<int> TAdjList;
typedef vector<TAdjList> TAdjLists;

static void Calc(int N, int M, TVertices &vertices, const TAdjLists &adjLists, int src, int dst) {
    deque<int> q;
    q.push_back(src);

    while (!q.empty()) {
        const int fromIdx = q.front();
        q.pop_front();
        TVertex &from = vertices[fromIdx];

        bool addAgain = false;

        const TAdjList &lst = adjLists[fromIdx];
        for (TAdjList::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
            const int toIdx = *iter;
            TVertex &to = vertices[toIdx];

            int newCost = from.Cost;
            if (fromIdx < toIdx) {
                //if (from.Direction ==
            } else {

            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    TAdjLists adjLists(N);
    for (int i = 0; i < M; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        adjLists[from].push_back(to);
    }

    int src, dst;
    scanf("%d %d", &src, &dst);

    TVertices vertices(N);
    Calc(N, M, vertices, adjLists, src, dst);
    return 0;
}
