#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

class TSolver {
private:
    map<int, int> Start2ID;
    map<int, int, greater<int> > Len2ID;
public:
    explicit TSolver(int total)
    {
        Start2ID.insert(make_pair(
            0, total
        ));
        Len2ID.insert(make_pair(
            total, 0
        ));
    }

    void AddSplit(int x) {

    }

    //
};

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    TSolver xsolver(w);
    TSolver ysolver(h);

    for (int i = 1; i <= n; ++i) {
        string type;
        int where;
        cin >> type >> where;
        if (type == "H") {
            ysolver.AddSplit(where);
        } else {
            xsolver.AddSplit(where);
        }
    }

    return 0;
}
