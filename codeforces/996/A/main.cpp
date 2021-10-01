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

    int N;
    cin >> N;

    int res = 0;

    for (auto p : {100, 20, 10, 5, 1})
    {
        const auto d = N / p;
        res += d;
        N -= (d * p);
        //cout << "p: " << p << "\td: " << d << endl;
    }

    cout << res << endl;

    return 0;
}
