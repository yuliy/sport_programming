#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

static bool IsRightTriangle(int a, int b, int c) {
    return a*a + b*b == c*c;
    /*
    vector<int> v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;

    sort(v.begin(), v.end());

    return (v[0]*v[0] + v[1]*v[1]) == (v[2]*v[2]);
    */
}

static int SolutionsCount(int P) {
    int res = 0;
    for (int a = 1; a <= (P-2); ++a) {
        for (int b = a; b <= (P-a-1); ++b) {
            const int c = P-a-b;
            if (c < b)
                continue;
            const bool rt = IsRightTriangle(a, b, c);
            //cout << P << "\t" << a << "\t" << b << "\t" << "\t" << c << "\trt=" << rt << endl;
            if (rt)
                ++res;
        }
    }
    return res;
}

int main() {
    int maxSols = 0;
    int maxP = 0;

    for (int p = 3; p <= 1000; ++p) {
        cout << "\tp=" << p << endl;

        const int curSols = SolutionsCount(p);
        if (curSols >= maxSols) {
            maxSols = curSols;
            maxP = p;
        }
    }

    cout << "maxSols=" << maxSols << endl
         << "maxP=" << maxP << endl;

    return 0;
}
