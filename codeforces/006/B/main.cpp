#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    char pc;
    scanf("%d %d %c", &n, &m, &pc);

    char plan[100][100];
    for (int i = 0; i < n; ++i) {
        scanf("%s", plan[i]);
    }

    int left = 1000;
    int right = -1000;
    int top = 1000;
    int bottom = -1000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (plan[i][j] == pc) {
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        }
    }

    set<char> colors;

    for (int i = top; i <= bottom; ++i) {
        if (left > 0)
            colors.insert(plan[i][left-1]);

        if (right < (m-1))
            colors.insert(plan[i][right+1]);
    }

    for (int i = left; i <= right; ++i) {
        if (top > 0)
            colors.insert(plan[top-1][i]);

        if (bottom < (n-1))
            colors.insert(plan[bottom+1][i]);
    }

    colors.erase('.');
    printf("%d\n", (int)colors.size());
    return 0;
}
