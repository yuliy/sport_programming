#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int M, N;
typedef map<int, int, greater<int> > TNum2Count;
TNum2Count dic;

int main() {
    scanf("%d\n", &M);

    vector<int> v;
    for (;;) {
        int tmp;
        scanf("%d\n", &tmp);
        if (tmp == -1)
            break;
        v.push_back(tmp);
    }
    N = v.size();

    for (int i = 0; i < M; ++i)
        ++dic[v[i]];

    for (int i = M; i <= N; ++i) {
        TNum2Count::iterator maxIter = dic.begin();
        printf("%d\n", maxIter->first);
        if (dic[v[i-M]] > 1) {
            --dic[v[i-M]];
        } else {
            TNum2Count::iterator it = dic.find(v[i-M]);
            dic.erase(it);
        }

        ++dic[v[i]];
    }

    return 0;
}
