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

int main() {
    int n, m;
    cin >> n >> m;

    map<string, string> dict;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        dict[a] = (a.size() <= b.size()) ? a : b;
    }

    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        if (i != (n-1))
            cout << dict[c] << ' ';
        else
            cout << dict[c] << endl;
    }

    return 0;
}
