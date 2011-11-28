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
    int a, b;
    cin >> a >> b;

    int res1 = 0;
    {
        res1 = 80;
        if (b > 40)
            res1 += ((b - 40) * 2);
        res1 += 40;
    }
    
    int res2 = 0;
    {
        res2 = 39 * 2;
        res2 += ((a - 40) * 2);
        res2 += 40;
        res2 += 1;
    }

    const int res = max(res1, res2);
    printf("%d\n", res);

    return 0;
}
