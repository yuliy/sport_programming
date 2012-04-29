#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
using namespace std;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

enum EColour {
    C_BLACK,
    C_RED,
};

template<typename T>
struct TNode {
    EColour Colour;
    TNode *Parent, *Left, *Right;
    T Key;

    TNode()
        : Colour(C_BLACK)
        , Parent(0)
        , Left(0)
        , Right(0)
        , Key(T()) {
    }

    TNode(EColour colour, TNode *parent, TNode *left, TNode *right, const T &key)
        : Colour(colour)
        , Parent(parent)
        , Left(left)
        , Right(right)
        , Key(key) {
    }
};

template<typename T, typename TComparator = std::less<T> >
class TRBTree {
private:
    TNode *Root;
    //TNode *Sentinel;
    TComparator Cmp;
private:
    void LeftRotate(TNode *x) {
        TNode *y = x->Right;        // set y
        x->Right = y->Left;         // turn y's left subtree into x's right subtree
        if (y->Left != 0)
            y->Left->Parent = x;
        y->Parent = x->Parent;
        if (x->Parent == 0)
            Root = y;
        else if (x == x->Parent->Left)
            x->Parent->Left = y;
        else
            x->Parent->Right = y;
        y->Left = x;
        x->Parent = y;
    }

    void RightRotate(TNode *y) {
        TNode *x = y->Left;
        y->Left = x->Right;
        if (x->Right != 0)
            x->Right->Parent = y;
        x->Parent = y->Parent;
        if (y->Parent == 0)
            Root = x;
        else if (y == y->Parent->Left)
            y->Parent->Left = x;
        else
            y->Parent->Right = x;
        x->Right = y;
        y->Parent = x;
    }

    void Insert(TNode *z) {
        TNode *y = 0;
        TNode *x = Root;
        while (x != 0) {
            y = x;
            x = Cmp(z->Key, x->Key) ? x->Left : x->Right;
        }

        z->Parent = y;
        if (y == 0)
            Root = z;
        else if (Cmp(z->Key, y->Key))
            y->Left = z;
        else
            y->Right = z;
        z->Left = 0;
        z->Right = 0;
        z->Colour = C_RED;
        InsertFixup(z);
    }
public:
    TRBTree()
        : Cmp(TComparator())
        , Root(0) {
        //, Sentinel (new TNode()) {
     }

    TRBTree(TComparator cmp)
        : Cmp(cmp)
        , Root(0) {
        //, Sentinel(new TNode()) {
    }
};

int main( int argc, char** argv ) {
    try {
        //srand( time(NULL) );
        //Test();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
