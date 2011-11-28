#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 32;
int ms[MAX_SIZE][MAX_SIZE];

typedef map<string, int> TName2Idx;
TName2Idx name2idx;

static int GetIdxByName(const char *s) {
    TName2Idx::const_iterator it = name2idx.find(s);
    if (it == name2idx.end())
        name2idx.insert(make_pair(string(s), name2idx.size()));
    return name2idx[s];
}

static int GetGatesCount() {
    return name2idx.size();
}

static void Init() {
    for (int i = 0; i < MAX_SIZE; ++i)
        for (int j = 0; j < MAX_SIZE; ++j)
            ms[i][j] = 0;
}

static void ShowDic() {
    for (TName2Idx::const_iterator iter = name2idx.begin(), end = name2idx.end(); iter != end; ++iter)
        cout << iter->first << "\t" << iter->second << endl;
}

static void ShowMS() {
    const int sz = GetGatesCount();
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            cout << ms[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    Init();

    char gate[64];
    scanf("%s", gate);
    const int gateIdx = GetIdxByName(gate);

    for (;;) {
        char buf[128];
        scanf("%s", buf);
        if (buf[0] == '#')
            break;

        char *delim = strchr(buf, '-');

        char first[64];
        char second[64];
        strncpy(first, buf, delim - buf);
        first[delim-buf] = 0;
        strcpy(second, delim+1);

        const int i = GetIdxByName(first);
        const int j = GetIdxByName(second);
        ms[i][j] = ms[j][i] = 1;
    }

    //ShowDic();
    //ShowMS();

    const int gatesCnt = GetGatesCount();
    vector<int> prev;
    vector<int> next;
    set<int> marked;

    prev.push_back(0);
    int depth = 0;
    for (;;) {
        for (vector<int>::const_iterator iter = prev.begin(), end = prev.end(); iter != end; ++iter) {
            const int idx = *iter;
            for (int i = 0; i < gatesCnt; ++i) {
                if ((i != idx) && ms[idx][i] && (marked.find(i) == marked.end())) {
                    next.push_back(i);
                    marked.insert(i);
                }
            }
        }
        prev.swap(next);
        next = vector<int>();
        if (prev.size() == 0)
            break;

        ++depth;
    }

    //printf("%d\n", 2*depth);
    printf("%d\n", (gatesCnt == 0) ? 0 : (gatesCnt-1));

    return 0;
}
