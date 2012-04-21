#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
#include "graph.h"
using namespace std;
using namespace NGraphLib;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

struct TVertex {
    int Num;

    TVertex() : Num(-1) {}
    TVertex(int num) : Num(num) {}
};

static void Test() {
    // Reading graph
    int N, M;
    scanf("%d %d", &N, &M);

    typedef TALGraph<TVertex> TGraph;
    typedef vector< TGraph::TVertexDescriptor > TVDescriptors;
    TGraph g;
    TVDescriptors vdescriptors;
    for (int i = 0; i < N; ++i) {
        TVertex v(i + 1);
        TGraph::TVertexDescriptor vd = g.AddVertex(v);
        vdescriptors.push_back( vd );
    }

    for (int i = 0; i < M; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        g.AddEdge(vdescriptors[from-1], vdescriptors[to-1]);
    }

    BreadthFirstSearch(g, TBFSHandler);
}

int main( int argc, char** argv ) {
    try {
        //srand( time(NULL) );
        Test();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
