#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static bool IsRightTriangle(int a, int b, int c) {
    vector<int> v(3);
    v[0] = a;
    v[1] = b;
    v[3] = c;

    sort(v.begin(), v.end());

    return (sqr(v[0]) + sqr(v[1]) == sqr(v[2]));
        
}

int main() {

    return 0;
}
