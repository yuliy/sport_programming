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

int CalcDigits(ui64 n) {
    int res = 1;
    ui64 tmp = 6;
    while (tmp < n) {
        tmp *= 7;
        ++res;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << CalcDigits(n) << endl
        << CalcDigits(m) << endl;
    return 0;
}
