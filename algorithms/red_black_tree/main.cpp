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
    T Value;

    TNode()
        : Colour(C_BLACK)
        , Parent(0)
        , Left(0)
        , Right(0)
        , Value(T()) {
    }

    TNode(EColour colour, TNode *parent, TNode *left, TNode *right, const T &value)
        : Colour(colour)
        , Parent(parent)
        , Left(left)
        , Right(right)
        , Value(value) {
    }
};

template<typename T, typename TComparator = std::less<T> >
class TRBTree {
private:
    TNode *Root;
    TComparator Cmp;
public:
    TRBTree()
        : Cmp(TComparator())
        , Root(0) {
    }

    TRBTree(TComparator cmp)
        : Cmp(cmp)
        , Root(0) {
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
