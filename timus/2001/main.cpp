#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int a1, a2, a3;
    int b1, b2, b3;
    cin
        >> a1 >> b1
        >> a2 >> b2
        >> a3 >> b3;
    cout
        << (a1 - a3) << ' '
        << (b1 - b2) << endl;
    return 0;
}
