#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef vector<int> TAdjList;
typedef vector<TAdjList> TAdjLists;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    TAdjLists adjLists(N);
    for (int i = 0; i < M; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        adjLists[from].push_back(to);
    }

    return 0;
}
