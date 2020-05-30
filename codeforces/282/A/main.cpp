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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        x += (s == "++X" || s == "X++") ? 1 : -1;
    }
    cout << x << endl;

    return 0;
}
