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
//using namespace NGraphLib;

struct TVertex {
    int Num;

    TVertex() : Num(-1) {}
    TVertex(int num) : Num(num) {}
};

typedef NGraphLib::TALGraph<TVertex> TGraph;
typedef vector< TGraph::TVertexDescriptor > TVDescriptors;

void PrintVertices(const TGraph &g) {
    pair< TGraph::TVertexIterator, TGraph::TVertexIterator > p = g.GetVertices();
    for (; p.first != p.second; ++p.first) {
        TGraph::TVertexDescriptor vd = *(p.first);
        const TVertex &v = g.GetVertex(vd);
        cout << v.Num << endl;
    }
}

void PrintEdges(const TGraph &g) {
    pair< TGraph::TEdgeIterator, TGraph::TEdgeIterator > p = g.GetEdges();
    for (; p.first != p.second; ++p.first) {
        TGraph::TEdgeDescriptor ed = *(p.first);
        const TVertex &from = g.GetVertex(ed.From());
        const TVertex &to = g.GetVertex(ed.To());
        cout << from.Num << "\t" << to.Num << endl;
    }
}

static void Test() {
    // Reading graph
    int N, M;
    scanf("%d %d", &N, &M);

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

    //
    //PrintVertices(g);
    //PrintEdges(g);

    //BreadthFirstSearch(g, TBFSHandler);
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
