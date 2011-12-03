#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int N;
int Q;

typedef set<int> TCities;
typedef map<int, TCities > TPeople2Cities;
TPeople2Cities dic;

static bool Check(int l, int r, int x) {
    TPeople2Cities::const_iterator pciter = dic.find(x);
    if (pciter == dic.end())
        return false;

    const TCities &cities = pciter->second;
    TCities::const_iterator citer1 = cities.lower_bound(l);
    TCities::const_iterator citer2 = cities.upper_bound(r);
    return citer1 != citer2;
}

int main() {
    scanf("%d\n", &N);
    for (int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        dic[tmp].insert(i);
    }

    scanf("%d\n", &Q);
    for (int i = 1; i <= Q; ++i) {
        int l, r, x;
        scanf("%d %d %d\n", &l, &r, &x);
        if (Check(l, r, x))
            printf("1");
        else
            printf("0");
    }

    printf("\n");
    return 0;
}
