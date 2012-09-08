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
    int n;
    scanf("%d", &n);

    int c[5] = {0};

    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++c[tmp];
    }

    int res = n;
    if (c[1] == 4)
        res -= 3;
    else if (c[1] == 

    return 0;
}
