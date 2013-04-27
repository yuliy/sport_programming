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
#include "tools.h"

using namespace std;
using namespace ystd;

typedef TRBTree<TFoo> TTree;
typedef vector< const TTree::TNode* > TCPNodes;

static void PrintNode(const TTree::TNode &node) {
    cout << "-------------- NODE -------------------" << endl
        << "Key: " << node.Key.Value << endl
        << "Colour: " << ((node.Colour == TTree::C_BLACK) ? "BLACK" : "RED") << endl;

    cout << "Parent: ";
    if (node.Parent)
        cout << node.Parent->Key.Value << endl;
    else
        cout << "NULL" << endl;

    cout << "Left: ";
    if (node.Left)
        cout << node.Left->Key.Value << endl;
    else
        cout << "NULL" << endl;

    cout << "Right: ";
    if (node.Right)
        cout << node.Right->Key.Value << endl;
    else
        cout << "NULL" << endl;
}

static void TestRBTree() {
    // Creating random tree
    TTree tree;
    TCPNodes nodes;
    for (int i = 0; i < 10; ++i) {
        TFoo foo(rand() % 100);
        TTree::TNode *node = new TTree::TNode(foo);
        nodes.push_back(node);
        tree.SimpleInsert(node);
    }

    // Printing tree content
    for (TCPNodes::const_iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
        PrintNode(**iter);

    // Printing tree in ascending order
    cout << "Tree elements in ascending order:" << endl;
    for (const TTree::TNode *node = tree.Minimum(); node; node = tree.Successor(node))
        cout << node->Key.Value << endl;

    // Printing tree in descending order
    cout << "Tree elements in descending order:" << endl;
    for (const TTree::TNode *node = tree.Maximum(); node; node = tree.Predecessor(node))
        cout << node->Key.Value << endl;
}

int main( int argc, char** argv ) {
    try {
        TestRBTree();
        TFoo::PrintStats();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
