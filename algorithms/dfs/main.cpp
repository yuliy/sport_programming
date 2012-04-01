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
    int FinitishingTime;

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

static void DFS(TVertices &vertices, const vector< vector<int> > &adjList, int sourceIdx) {
}

static void DFS(TVertices &vertices, const vector< vector<bool> > &adjMatrix, int sourceIdx) {
}

static void CreateGraph(TVertices &vertices, vector< vector<int> > &adjList) {
    vertices.clear();
    vertices.resize(8);

    vector< vector<int> > al;
    al.resize(8);

    al[0].push_back(1);
    al[0].push_back(4);

    al[1].push_back(0);
    al[1].push_back(5);

    al[2].push_back(3);
    al[2].push_back(5);
    al[2].push_back(6);

    al[3].push_back(2);
    al[3].push_back(6);
    al[3].push_back(7);

    al[4].push_back(0);

    al[5].push_back(1);
    al[5].push_back(2);
    al[5].push_back(6);

    al[6].push_back(2);
    al[6].push_back(3);
    al[6].push_back(5);
    al[6].push_back(7);

    al[7].push_back(3);
    al[7].push_back(6);

    adjList.swap(al);
}

static void CreateGraph(TVertices &vertices, vector< vector<bool> > &adjMatrix) {
    vertices.clear();
    vertices.resize(8);

    vector< vector<bool> > am;
    vector<bool> tmp(8);
    for (int i = 0; i < 8; ++i)
        am.push_back(tmp);

    am[0][1] = true;
    am[0][4] = true;

    am[1][0] = true;
    am[1][5] = true;

    am[2][3] = true;
    am[2][5] = true;
    am[2][6] = true;

    am[3][2] = true;
    am[3][6] = true;
    am[3][7] = true;

    am[4][0] = true;

    am[5][1] = true;
    am[5][2] = true;
    am[5][6] = true;

    am[6][2] = true;
    am[6][3] = true;
    am[6][5] = true;
    am[6][7] = true;

    am[7][3] = true;
    am[7][6] = true;

    adjMatrix.swap(am);
}

static void Test1() {
    TVertices vertices;
    vector< vector<int> > adjList;
    CreateGraph(vertices, adjList);

    DFS(vertices, adjList, 1);
    PrintVertices(vertices);
}

static void Test2() {
    TVertices vertices;
    vector< vector<bool> > adjMatrix;
    CreateGraph(vertices, adjMatrix);

    DFS(vertices, adjMatrix, 1);
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
