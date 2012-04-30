#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
#include "rbtree.h"
using namespace std;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

static void Test() {
    TRBTree<int> t;

    // filling with data
    const int cnt = 15;
    for (int i = 0; i < cnt; ++i) {
        cout << "inserting: " << i << endl;
        TNode<int> *n = new TNode<int>();
        n->Key = i;
        t.Insert(n);
    }

    // printing all tree structure
    deque< TNode<int>* > q;
    q.push_back(t.Root);
    while (!q.empty()) {
        TNode<int> *n = q.front();
        q.pop_front();

        cout << "(" << n->Key << ")\t"
            << "c=" << ((n->Colour == C_BLACK) ? "B" : "R") << "\t"
            << "p=" << (n->Parent ? n->Parent->Key : -1) << "\t"
            << "l=" << (n->Left ? n->Left->Key : -1) << "\t"
            << "r=" << (n->Right ? n->Right->Key : -1) << endl;

        if (n->Left)
            q.push_back(n->Left);
        if (n->Right)
            q.push_back(n->Right);
    }

    //
    TNode<int> *x = t.Minimum(t.Root);
    while (x) {
        cout << x->Key << endl;
        x = t.Successor(x);
    }
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
