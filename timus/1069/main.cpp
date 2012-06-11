#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <priority_queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef vector<int> TVertices;
typedef map<int, int> TVertex2Count;
typedef priority_queue<int, greater<int> > TQueue;

int main() {
    TVertices vertices;
    TVertex2Count v2c;
    int tmp;
    while (scanf("%d", &tmp) != EOF) {
        vertices.push_back(tmp);
        ++v2c[tmp];
    }

    TQueue q;
    for (TVertex2Count::const_iterator iter = v2c.begin(), end = v2c.end(); iter != end; ++iter)
        if (iter->second == 0)
            q.push(iter->first);

    for (TVertices::const_iterator iter = vertices.begin(), end = vertices.end(); iter != end; ++iter) {
        const int v = *iter;
        const int minv = q.top();

        //
    }

    return 0;
}
