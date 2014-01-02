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
    int a, b;
    cin >> a >> b;

    int res = a;
    for (int cur = a; cur >= b; ++res) {
        cur -= (b-1);
    }

    cout << res << endl;

    return 0;
}
