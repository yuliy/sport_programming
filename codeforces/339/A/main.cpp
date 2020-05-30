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
    string s;
    cin >> s;
    vector<char> v;
    for (auto ch : s) {
        if (ch != '+') {
            v.push_back(ch);
        }
    }

    sort(v.begin(), v.end());
    const auto n = v.size();
    for (int i = 0; i < n; ++i) {
        cout << v[i];
        if (i != (n-1))
            cout << "+";
    }
    cout << endl;

    return 0;
}
