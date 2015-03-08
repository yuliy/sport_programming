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
    int n;
    scanf("%d", &n);

    vector<int> res(n+1);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        res[tmp] = i;
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
