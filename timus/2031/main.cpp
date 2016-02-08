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

    if (n > 4) {
        cout << "Glupenky Pierre" << endl;
        return 0;
    }

    vector<string> v = {"16", "06", "68", "88"};
    for (int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;

    return 0;
}
