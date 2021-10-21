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

    std::string h = "hello";
    std::string s;
    cin >> s;

    while (h.size() && s.size()) {
        if (h.back() == s.back())
            h.pop_back();
        s.pop_back();
    }

    cout << (h.empty() ? "YES" : "NO") << endl;

    return 0;
}
