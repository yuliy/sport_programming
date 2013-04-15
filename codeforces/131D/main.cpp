#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
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
        , Distance(1000000)
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

deque<int> Cycle;

static void MarkCycle() {
    //cout << "Cycle:" << endl;
    for (int i = 0; i < N; ++i) {
        TPoint &p = Points[i];
        if (p.Colour == GRAY) {
            //p.Distance = 0;
            Cycle.push_back(i);
            //cout << "\t" << (iter - Points.begin() + 1) << endl;
        }
    }
}

static bool DFSVisit(int u, int uParent) {
    TAdjList &lst = AdjLists[u];
    Points[u].Colour = GRAY;
    for (TAdjList::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        const int v = *iter;
        if (Points[v].Colour == WHITE) {
            if (DFSVisit(v, u))
                return true;
        } else if ((v != uParent) && (Points[v].Colour == GRAY)) {
            MarkCycle();
            return true;
        }
    }
    Points[u].Colour = BLACK;
    return false;
}

static void BFS() {
    deque<int> q = Cycle;
    for (deque<int>::iterator iter = q.begin(); iter != q.end(); ++iter) {
        Points[*iter].Colour = GRAY;
        Points[*iter].Distance = 0;
    }

    while (false == q.empty()) {
        const int v = q.front();
        q.pop_front();
        TAdjList &lst = AdjLists[v];
        for (TAdjList::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
            const int t = *iter;
            if (Points[t].Colour == WHITE) {
                Points[t].Colour = GRAY;
                //Points[t].Distance = min(Points[t].Distance, Points[v].Distance + 1);
                Points[t].Distance = Points[v].Distance + 1;
                q.push_back(t);
            }
        }
        Points[v].Colour = BLACK;
    }
}

static void MarkAllPointsWhite() {
    for (TPoints::iterator iter = Points.begin(); iter != Points.end(); ++iter)
        iter->Colour = WHITE;
}

int main() {
    Init();

    MarkAllPointsWhite();
    if (!DFSVisit(0, -1))
        cout << "Achtung! Cycle not found!" << endl;

    MarkAllPointsWhite();
    BFS();

    for (TPoints::iterator iter = Points.begin(); iter != Points.end(); ++iter)
        cout << iter->Distance << " ";
    cout << endl;

    return 0;
}
