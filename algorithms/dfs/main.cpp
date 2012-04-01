#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

enum EVColour {
    VC_WHITE = 0,
    VC_GRAY,
    VC_BLACK,
};

struct TVertex {
    EVColour Colour;
    int DiscoverTime;
    int FinishingTime;
    int ParentIdx;

    TVertex()
        : Colour(VC_WHITE)
        , DiscoverTime(-1)
        , FinishingTime(-1)
        , ParentIdx(-1) {
    }
};

typedef vector<TVertex> TVertices;

static void PrintVertices(const TVertices &vertices) {
    const int cnt = vertices.size();
    for (int i = 0; i < cnt; ++i) {
        cout << "#" << i << "\tcolour=";

        switch (vertices[i].Colour) {
        case VC_WHITE:  cout << "w\t"; break;
        case VC_GRAY:   cout << "g\t"; break;
        case VC_BLACK:  cout << "b\t"; break;
        }

        cout << "d=" << vertices[i].DiscoverTime << "\t"
            << "f=" << vertices[i].FinishingTime << "\t"
            << "p=" << vertices[i].ParentIdx << endl;
    }
}

int Time;

static void DFS_Visit(TVertices &vertices, const vector< vector<int> > &adjList, int uIdx) {
    TVertex &u = vertices[uIdx];
    u.Colour = VC_GRAY;
    u.DiscoverTime = ++Time;

    const vector<int> &adj = adjList[uIdx];
    for (vector<int>::const_iterator iter = adj.begin(), end = adj.end(); iter != end; ++iter) {
        TVertex &v = vertices[*iter];
        if (v.Colour == VC_WHITE) {
            v.ParentIdx = uIdx;
            DFS_Visit(vertices, adjList, *iter);
        }
    }

    u.Colour = VC_BLACK;
    u.FinishingTime = ++Time;
}

static void DFS(TVertices &vertices, const vector< vector<int> > &adjList) {
    for (TVertices::iterator iter = vertices.begin(), end = vertices.end(); iter != end; ++iter) {
        iter->Colour = VC_WHITE;
        iter->ParentIdx = -1;
    }

    Time = 0;
    const int cnt = vertices.size();
    for (int i = 0; i < cnt; ++i) {
        TVertex &u = vertices[i];
        if (u.Colour == VC_WHITE)
            DFS_Visit(vertices, adjList, i);
    }
}

static void DFS_Visit(TVertices &vertices, const vector< vector<bool> > &adjMatrix, int uIdx) {
    TVertex &u = vertices[uIdx];
    u.Colour = VC_GRAY;
    u.DiscoverTime = ++Time;

    const vector<bool> &adj = adjMatrix[uIdx];
    const int adjCnt = adj.size();
    for (int i = 0; i < adjCnt; ++i) {
        if (adj[i] == false)
            continue;

        TVertex &v = vertices[i];
        if (v.Colour == VC_WHITE) {
            v.ParentIdx = uIdx;
            DFS_Visit(vertices, adjMatrix, i);
        }
    }

    u.Colour = VC_BLACK;
    u.FinishingTime = ++Time;
}

static void DFS(TVertices &vertices, const vector< vector<bool> > &adjMatrix) {
    for (TVertices::iterator iter = vertices.begin(), end = vertices.end(); iter != end; ++iter) {
        iter->Colour = VC_WHITE;
        iter->ParentIdx = -1;
    }

    Time = 0;
    const int cnt = vertices.size();
    for (int i = 0; i < cnt; ++i) {
        TVertex &u = vertices[i];
        if (u.Colour == VC_WHITE)
            DFS_Visit(vertices, adjMatrix, i);
    }
}

static void CreateGraph(TVertices &vertices, vector< vector<int> > &adjList) {
    vertices.clear();
    vertices.resize(6);

    vector< vector<int> > al;
    al.resize(6);

    al[0].push_back(1);
    al[0].push_back(3);

    al[1].push_back(4);

    al[2].push_back(4);
    al[2].push_back(5);

    al[3].push_back(1);

    al[4].push_back(3);

    al[5].push_back(5);

    adjList.swap(al);
}

static void CreateGraph(TVertices &vertices, vector< vector<bool> > &adjMatrix) {
    vertices.clear();
    vertices.resize(6);

    vector< vector<bool> > am;
    vector<bool> tmp(6);
    for (int i = 0; i < 6; ++i)
        am.push_back(tmp);

    am[0][1] = true;
    am[0][3] = true;

    am[1][4] = true;

    am[2][4] = true;
    am[2][5] = true;

    am[3][1] = true;

    am[4][3] = true;

    am[5][5] = true;

    adjMatrix.swap(am);
}

static void Test1() {
    TVertices vertices;
    vector< vector<int> > adjList;
    CreateGraph(vertices, adjList);

    DFS(vertices, adjList);
    PrintVertices(vertices);
}

static void Test2() {
    TVertices vertices;
    vector< vector<bool> > adjMatrix;
    CreateGraph(vertices, adjMatrix);

    DFS(vertices, adjMatrix);
    PrintVertices(vertices);
}

int main( int argc, char** argv ) {
    try {
        Test1();
        cout << "==============================================" << endl;
        Test2();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
