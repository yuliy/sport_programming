#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

set<long long> pentagonals;
set<long long> hexagonals;

static void Init() {
    cout << "Calculating precompute..." << endl;
    for (long long n = 1; n < 100 * 1000; ++n) {
        pentagonals.insert( n * (3*n - 1) / 2 );
        hexagonals.insert( n * (2*n - 1) );
    }
    cout << "\tcompleted." << endl;
    cout << "P count: " << pentagonals.size() << endl;
    cout << "H count: " << hexagonals.size() << endl;
    cout << *pentagonals.rbegin() << endl;
    cout << *hexagonals.rbegin() << endl;
}

int main() {
    Init();

    for (long long n = 286; ; ++n) {
        const long long Tn = n * (n + 1) / 2;
        if (n % 1000000 == 0)
            cout << "\tcur n:\t" << n << "\tTn=" << Tn << endl;
        if (pentagonals.find(Tn) == pentagonals.end())
            continue;
        if (hexagonals.find(Tn) == hexagonals.end())
            continue;
        cout << "Result: " << Tn << endl;
        break;
    }

    cout << "Done." << endl;

    return 0;
}
