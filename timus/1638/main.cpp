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
    int paperWidth, lacingWidth, begNum, endNum;
    cin >> paperWidth >> lacingWidth >> begNum >> endNum;
    
    int res = 0;
    if (begNum < endNum) {
        res += 2 * lacingWidth;
        for (int i = begNum+1; i < endNum; ++i) {
            res += paperWidth;
            res += 2 * lacingWidth;
        }
    } else if (begNum > endNum) {
        res += 2 * paperWidth;
        res += 2 * lacingWidth;
        for (int i = begNum-1; i > endNum; --i) {
            res += paperWidth;
            res += 2 * lacingWidth;
        }
    } else {
        res = paperWidth;
    }

    cout << res << endl;

    return 0;
}
