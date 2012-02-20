#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef map<int, map<int, int> > TBeg2End2Val;

int main() {
    int N;
    int Q;
    char buf[8];

    for (;;) {
        scanf("%d", &N);
        if (N == -1)
            continue;

        scanf("%d", &Q);

        TBeg2End2Val beg2end2val;
        for (int i = 0; i < Q; ++i) {
            int beg, end;
            scanf("%d %d %s", buf);
        }
    }

    return 0;
}
