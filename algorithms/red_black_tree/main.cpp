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

static void PrintNode(const TTree::TNode *pnode) {
    if (!pnode)
        throw TRBTException("Error in PrintNode: pnode == NULL");

    const TTree::TNode &node = *pnode;
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

static void PrintTree(const TTree::TNode *node) {
    if (!node) {
        cout << "Empty tree." << endl;
        return;
    }

    if (node->Left)
        PrintNode(node->Left);
    PrintNode(node);
    if (node->Right)
        PrintNode(node->Right);
}

static void TestRBTree() {
    // Creating random tree
    TTree tree;
    for (int i = 0; i < 10; ++i) {
        TFoo foo(rand() % 100);
        TTree::TNode *node = new TTree::TNode(foo);
        tree.Insert(node);
    }

    PrintTree(tree.GetRoot());

    // Printing tree in ascending order
    cout << "Tree elements in ascending order:" << endl;
    for (const TTree::TNode *node = tree.Minimum(); node; node = tree.Successor(node))
        cout << node->Key.Value << endl;

    // Printing tree in descending order
    cout << "Tree elements in descending order:" << endl;
    for (const TTree::TNode *node = tree.Maximum(); node; node = tree.Predecessor(node))
        cout << node->Key.Value << endl;

    while (!tree.Empty()) {
        const TTree::TNode *root = tree.GetRoot();
        cout << "root: " << (root->Key.Value) << endl;
        tree.Delete(root);
    }

    PrintTree(tree.GetRoot());
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
