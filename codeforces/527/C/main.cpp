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
#include <exception>
using namespace std;

typedef map<int, int> TStart2ID;
typedef map<int, int, greater<int> > TLen2ID;

class TSolver {
private:
    int Total;
    TStart2ID Start2ID;
    TLen2ID Len2ID;
private:
    TLen2ID::iterator FindInterval(int len, int id) {
        auto range = Len2ID.equal_range(len);
        for (
            TLen2ID::iterator it = range.first;
            it != range.second;
            ++it
        ) {
            if (it->second == id) {
                return it;
            }
        }

        throw logic_error("FindInterval failed searching!");
    }
public:
    explicit TSolver(int total)
        : Total(total)
    {
        Start2ID.insert(make_pair(
            0, total
        ));
        Len2ID.insert(make_pair(
            total, 0
        ));
    }

    int GetMax() const {
        return Len2ID.begin()->first;
    }

    void AddSplit(int x, int id) {
        //
        TStart2ID::iterator lb = Start2ID.lower_bound(x);
        const int intervalStart = lb->first;
        const int intervalID = lb->second;
        ++lb;
        const int intervalLen = (lb == Start2ID.end()) ? Total : (lb->first - intervalStart);
        --lb;
        if (lb == Start2ID.end())
            throw logic_error("lb should be valid!");
        Start2ID.erase(lb);

        cout << "---AddSplit" << endl
            << "intervalStart: " << intervalStart << endl
            << "intervalID: " << intervalID << endl
            << "intervalLen: " << intervalLen << endl;

        //
        TLen2ID::iterator lenIter = FindInterval(intervalLen, intervalID);
        Len2ID.erase(lenIter);

        //
        Start2ID.insert(make_pair(
            intervalStart, intervalID
        ));
        Start2ID.insert(make_pair(
            x, id
        ));

        Len2ID.insert(make_pair(
            x - intervalStart, intervalID
        ));
        Len2ID.insert(make_pair(
            intervalStart + intervalLen - x, id
        ));
    }
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
            ysolver.AddSplit(where, i);
        } else {
            xsolver.AddSplit(where, i);
        }
    }

    const int res = xsolver.GetMax() * ysolver.GetMax();
    cout << res << endl;

    return 0;
}
