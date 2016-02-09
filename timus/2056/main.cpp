#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c3 = 0;
    int c4 = 0;
    int c5 = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp == 3) ++c3;
        if (tmp == 4) ++c4;
        if (tmp == 5) ++c5;
    }

    const double avg = (c3 * 3 + c4 * 4 + c5 * 5) * 1.0 / n;

    if (c3 != 0) {
        cout << "None" << endl;
        return 0;
    }

    if (c5 == n) {
        cout << "Named" << endl;
        return 0;
    }

    if (avg >= 4.5) {
        cout << "High" << endl;
        return 0;
    }

    cout << "Common" << endl;
    return 0;
}
