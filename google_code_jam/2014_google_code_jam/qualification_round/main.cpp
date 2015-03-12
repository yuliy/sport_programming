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

typedef vector<int> TRow;
typedef vector<TRow> TMat;

static TMat ParseMat() {
    TMat m;
    for (int i = 0; i < 4; ++i) {
        TRow r(4);
        cin >> r[0] >> r[1] >> r[2] >> r[3];
        m.push_back(r);
    }
    return m;
}

static string SolveSingleCase() {
    int firstRowIdx;
    cin >> firstRowIdx;
    const TMat& firstMat = ParseMat();
    const TRow& firstRow = firstMat[firstRowIdx-1];

    int secondRowIdx;
    cin >> secondRowIdx;
    const TMat& secondMat = ParseMat();
    const TRow& secondRow = secondMat[secondRowIdx-1];

    set<int> common;
    for (auto f : firstRow) {
        if (find(secondRow.begin(), secondRow.end(), f) != secondRow.end()) {
            common.insert(f);
        }
    }

    if (common.size() == 0) {
        return "Volunteer cheated!";
    }

    if (common.size() > 1) {
        return "Bad magician!";
    }

    return to_string( *common.begin() );
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
