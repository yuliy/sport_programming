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

static void TestRBTree() {
    //TRBTree<
}

int main( int argc, char** argv ) {
    try {
        TestRBTree();
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
