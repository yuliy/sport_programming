#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

enum EDiag {
    D_UNDEFINED = 0,
    D_HUNGRY    = 1,
    D_SATISFIED = 2
};

int main() {
    int n;
    scanf("%d", &n);

    map<int, EDiag> m;
    m[2] = D_HUNGRY;
    m[10] = D_SATISFIED;

    for (int i = 0; i < n; ++i) {
        int tmp;
        char buf[32];
        scanf("%d %s", &tmp, buf);
        const EDiag diag = (strcmp(buf, "hungry") == 0) ? D_HUNGRY : D_SATISFIED;
        map<int, EDiag>::iterator iter = m.find(tmp);
        if (iter == m.end()) {
            m[tmp] = diag;
        } else {
            if (iter->second != diag) {
                printf("Inconsistent\n");
                return 0;
            }
        }
    }

    for (map<int, EDiag>::const_iterator iter = m.begin(), end = m.end(); iter != end; ++iter) {
        //cout << iter->first << ";" << iter->second << endl;
        map<int, EDiag>::const_iterator nextIter = iter;
        ++nextIter;
        if (nextIter != end) {
            if (iter->second == D_SATISFIED && nextIter->second == D_HUNGRY) {
                printf("Inconsistent\n");
                return 0;
            }
        }
    }

    for (map<int, EDiag>::const_iterator iter = m.begin(), end = m.end(); iter != end; ++iter) {
        if (iter->second == D_SATISFIED) {
            printf("%d\n", iter->first);
            return 0;
        }
    }

    return 0;
}
