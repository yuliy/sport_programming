#include <cstdlib>
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <sys/time.h>
using namespace std;

const bool DEBUG_LOG = false;
//const bool DEBUG_LOG = true;

typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

typedef vector<int> TAdjList;

struct TVertex {
    bool Explored;
    int FinishingTime;

    TVertex()
        : Explored(false)
        , FinishingTime(-1) {
    }

    TAdjList AdjList;
};

typedef vector<TVertex> TVertices;

struct TGraph {
    TVertices Vertices;
    int Time;
    vector<int> SortedVertices;

    TGraph() {
    }

    void CreateTransposed(TGraph &res) const {
        const int vcount = Vertices.size();
        res.Vertices.clear();
        res.Vertices.resize(vcount);

        for (int from = 0; from < vcount; ++from) {
            const TAdjList &adjList = Vertices[from].AdjList;
            for (TAdjList::const_iterator iter = adjList.begin(), end = adjList.end(); iter != end; ++iter) {
                const int to = *iter;
                res.Vertices[to].AdjList.push_back(from);
            }
        }
    }

    void MarkAllUnexplored() {
        for (TVertices::iterator iter = Vertices.begin(), end = Vertices.end(); iter != end; ++iter)
            iter->Explored = false;
    }

    void ClearFinishingTimes() {
        for (TVertices::iterator iter = Vertices.begin(), end = Vertices.end(); iter != end; ++iter)
            iter->FinishingTime = -1;
    }

    void DFS1() {
        SortedVertices.clear();
        MarkAllUnexplored();
        ClearFinishingTimes();
        Time = 0;

        const int vcnt = Vertices.size();
        for (int i = 0; i < vcnt; ++i) {
            const TVertex &u = Vertices[i];
            if (u.Explored == false)
                DFS1_Visit(i);;
        }
    }

    void DFS1_Visit(int uidx) {
        TVertex &u = Vertices[uidx];
        u.Explored = true;
        if (DEBUG_LOG)
            cout << "DFS1_Visit: " << (uidx + 1) << endl;
        //++Time;

        const int adjCnt = u.AdjList.size();
        for (TAdjList::const_iterator iter = u.AdjList.begin(), end = u.AdjList.end(); iter != end; ++iter) {
            TVertex &v = Vertices[*iter];
            if (v.Explored == false)
                DFS1_Visit(*iter);
        }

        ++Time;
        u.FinishingTime = Time;
        SortedVertices.push_back(uidx);
    }

    void DFS2(const vector<int> &sortedVertices, vector<int> &sccs) {
        MarkAllUnexplored();
        for (vector<int>::const_reverse_iterator iter = sortedVertices.rbegin(), end = sortedVertices.rend(); iter != end; ++iter) {
            Time = 0;
            const TVertex &u = Vertices[*iter];
            if (u.Explored == false) {
                cout << "******" << endl;
                DFS2_Visit(*iter);
                cout << endl;
            }
            sccs.push_back(Time);
        }
    }

    void DFS2_Visit(int uidx) {
        TVertex &u = Vertices[uidx];
        u.Explored = true;
        cout << "\t" << (uidx + 1);

        const int adjCnt = u.AdjList.size();
        for (TAdjList::const_iterator iter = u.AdjList.begin(), end = u.AdjList.end(); iter != end; ++iter) {
            TVertex &v = Vertices[*iter];
            if (v.Explored == false)
                DFS2_Visit(*iter);
        }

        ++Time;
    }

    void CalcSCCs(vector<int> &sccs) {
        if (DEBUG_LOG) {
            cout << "input graph:" << endl;
            Print();
            cout << "=====================================================" << endl;
        }

        DFS1();
        TGraph tg;
        CreateTransposed(tg);

        if (DEBUG_LOG) {
            cout << "transposed graph:" << endl;
            tg.Print();
            cout << "=====================================================" << endl;

            cout << "sorted vertices:" << endl;
            for (vector<int>::const_iterator iter = SortedVertices.begin(), end = SortedVertices.end(); iter != end; ++iter) {
                TVertex &v = Vertices[*iter];
                cout << (*iter + 1) << " (" << v.FinishingTime << ")" << endl;
            }
        }

        tg.DFS2(SortedVertices, sccs);
    }

    void Print() const {
        const int vcnt = Vertices.size();
        for (int i = 0; i < vcnt; ++i) {
            cout << (i + 1) << ":";
            const TAdjList &adjList = Vertices[i].AdjList;
            for (TAdjList::const_iterator iter = adjList.begin(), end = adjList.end(); iter != end; ++iter) {
                cout << " " << (*iter + 1);
            }
            cout << endl;
        }
    }
};

int VCount = 0;
int ECount = 0;
//const int VCount = 9;
//const int ECount = 11;

void ReadGraph(TGraph &graph) {
    scanf("%d\t%d", &VCount, &ECount);
    cout << "|V|=" << VCount << "\t" << "|E|=" << ECount << endl;

    graph.Vertices.clear();
    graph.Vertices.resize(VCount);

    for (int i = 0; i < ECount; ++i) {
        int from, to;
        scanf("%d\t%d", &from, &to);
        graph.Vertices[from-1].AdjList.push_back(to-1);
    }
}

static void Test1() {
    TGraph g;
    ReadGraph(g);
    vector<int> sccs;
    g.CalcSCCs(sccs);
    cout << "sccs count = " << sccs.size() << endl
        << "sccs sizes:" << endl;

    sort(sccs.begin(), sccs.end());
    int sum = 0;
    for (vector<int>::const_iterator iter = sccs.begin(), end = sccs.end(); iter != end; ++iter) {
        cout << *iter << endl;
        sum += *iter;
    }
    cout << "sum=" << sum << endl;
}

int main( int argc, char** argv ) {
    try {
        //srand(time(NULL));
        Test1();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
