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

set<int> Products;

static void AnalyzePermutation(const int *v) {
    // a // b // product
    //for (int i = 0; i < 9; ++i)
    //    cout << v[i];
    //cout << endl;

    for (int aend = 0; aend < 5; ++aend) {
        for (int bend = aend + 1; bend < 6; ++bend) {
            int a = 0;
            {
                const int digitsCnt = aend + 1;
                for (int i = 0; i <= aend; ++i)
                    a += (v[i] * pow(10.0, digitsCnt - i - 1));
            }

            int b = 0;
            {
                const int digitsCnt = bend - aend;
                for (int i = aend + 1; i <= bend; ++i)
                    b += (v[i] * pow(10.0, digitsCnt - i + aend));
            }

            int p = 0;
            {
                const int digitsCnt = 9 - bend;
                for (int i = bend + 1; i < 9; ++i)
                    p += (v[i] * pow(10.0, digitsCnt - i + bend - 1));
            }

            if (a * b == p)
                Products.insert(p);
            //cout << "\taend=" << aend << "\ta=" << a << endl;
            //cout << "\tbend=" << bend << "\tb=" << b << endl;
            //cout << "\tproduct=" << p << endl;
            //cout << endl;
        }
    }
}

int main() {
    int v[9];
    for (v[0] = 1; v[0] < 10; ++v[0]) {
    for (v[1] = 1; v[1] < 10; ++v[1]) {
        if (v[1] == v[0])
            continue;
    for (v[2] = 1; v[2] < 10; ++v[2]) {
        if (v[2] == v[1] || v[2] == v[0])
            continue;
    for (v[3] = 1; v[3] < 10; ++v[3]) {
        if (v[3] == v[2] || v[3] == v[1] || v[3] == v[0])
            continue;
    for (v[4] = 1; v[4] < 10; ++v[4]) {
        if (v[4] == v[3] || v[4] == v[2] || v[4] == v[1] || v[4] == v[0])
            continue;
    for (v[5] = 1; v[5] < 10; ++v[5]) {
        if (v[5] == v[4] || v[5] == v[3] || v[5] == v[2] || v[5] == v[1] || v[5] == v[0])
            continue;
    for (v[6] = 1; v[6] < 10; ++v[6]) {
        if (v[6] == v[5] || v[6] == v[4] || v[6] == v[3] || v[6] == v[2] || v[6] == v[1] || v[6] == v[0])
            continue;
    for (v[7] = 1; v[7] < 10; ++v[7]) {
        if (v[7] == v[6] || v[7] == v[5] || v[7] == v[4] || v[7] == v[3] || v[7] == v[2] || v[7] == v[1] || v[7] == v[0])
            continue;
    for (v[8] = 1; v[8] < 10; ++v[8]) {
        if (v[8] == v[7] || v[8] == v[6] || v[8] == v[5] || v[8] == v[4] || v[8] == v[3] || v[8] == v[2] || v[8] == v[1] || v[8] == v[0])
            continue;
        AnalyzePermutation(v);
        //return 0;
    }
    }
    }
    }
    }
    }
    }
    }
    }
    int sum = 0;
    for (set<int>::const_iterator iter = Products.begin(), end = Products.end(); iter != end; ++iter)
        sum += *iter;
    cout << "Products count = " << Products.size() << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}
