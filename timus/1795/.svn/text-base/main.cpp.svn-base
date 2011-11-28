#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

struct TMan {
    int Count;
    string Type;
    bool Flag;

    TMan()
        : Count(0)
        , Flag(false) {
    }

    TMan(int cnt, string t)
        : Count(cnt)
        , Type(t)
        , Flag(false) {
    }
};

int main() {
    int m;
    scanf("%d", &m);

    map<string, int> dic;
    for (int i = 0; i < m; ++i) {
        int tmp;
        char buf1[8];
        char buf2[32];
        scanf("%d %s %s", &tmp, buf1, buf2);
        dic[buf2] = tmp;
    }

    int n;
    scanf("%d", &n);
    vector<TMan> v;
    for (int i = 0; i < n; ++i) {
        int tmp;
        char buf1[8];
        char buf2[32];
        scanf("%d %s %s", &tmp, buf1, buf2);
        v.push_back(TMan(tmp, buf2));
    }

    int t = 0;
    for (int i = 0; i < n; ++i) {
        TMan &man = v[i];

        int &c = dic[man.Type];
        if (c >= man.Count) {
            c -= man.Count;
            ++t;
        } else if (c == 0) {
            ++t;
        } else if (c > 0) {
            if (man.Flag) {
                c = 0;
            } else {
                if (i < (n-1)) {
                    man.Flag = true;
                    TMan &nextMan = v[i+1];
                    swap(man.Count, nextMan.Count);
                    swap(man.Type, nextMan.Type);
                    swap(man.Flag, nextMan.Flag);
                }
                --i;
            }
            ++t;
        }
    }

    printf("%d\n", t);

    return 0;
}
