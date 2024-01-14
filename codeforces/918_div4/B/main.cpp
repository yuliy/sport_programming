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

using ui64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    const string abc = "ABC";
    for (int i = 0; i < (t*3); ++i) {
        string s;
        cin >> s;
        for (auto ch : abc) {
            if (s.find(ch) == string::npos) {
                cout << ch << endl;
                break;
            }
        }
    }

    return 0;
}
