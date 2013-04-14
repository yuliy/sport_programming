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

typedef vector<int> TAdjList;
typedef vector<TAdjList> TAdjLists;

enum EColour {
    WHITE,
    GRAY,
    BLACK,
};

struct TPoint {
    EColour Colour;
    int Distance;

    TPoint()
        : Colour(WHITE)
        , Distance(std::numeric_limits<int>::max())
    {}
};

typedef vector<TPoint> TPoints;

int N;
TAdjLists AdjLists;
TPoints Points;

static void Init() {
    scanf("%d", &N);

    Points.resize(N);
    AdjLists.resize(N);

    for (int i = 0; i < N; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        --from;
        --to;
        AdjLists[from].push_back(to);
        AdjLists[to].push_back(from);
    }
}

static void MarkCycle() {
    for (TPoints::iterator iter = Points.begin(); iter != Points.end(); ++iter) {
        if (iter->Colour == GRAY)
            iter->Distance = 0;
    }
}

static void DFSVisit(int u) {
    TAdjList &lst = AdjLists[u];
    Points[u].Colour = GRAY;
    for (TAdjList::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        const int v = *iter;
        if (Points[v].Colour == WHITE) {
            DFSVisit(v);
        } else if (Points[v].Colour == GRAY) {
            MarkCycle();
            return;
        }
    }
    Points[u].Colour = BLACK;
}

static void BFS(int u) {
    deque<int> q;
    q.push_back(u);
    while (false == q.empty()) {
        const int v = q.front();
        q.pop_front();
        TAdjList &lst = AdjLists[v];
        for (TAdjList::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
            const int t = *iter;
            if (Points[t].Colour == WHITE) {
                Points[t].Colour = GRAY;
                Points[t].Distance = min(Points[t].Distance, Points[v].Distance + 1);
            }
        }
    }
}

int main() {
    Init();

    DFSVisit(0);

    for (int i = 0; i < N; ++i) {
        for (TPoints::iterator iter = Points.begin(); iter != Points.end(); ++iter)
            iter->Colour = WHITE;
        BFS(i);
    }

    for (TPoints::iterator iter = Points.begin(); iter != Points.end(); ++iter)
        cout << iter->Distance << " ";
    cout << endl;

    return 0;
}
