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

typedef unsigned long long ui64;
typedef long long i64;

int main() {
    ui64 a, b;
    cin >> a >> b;

    int res = 1;
    while (a && b && (a != b)) {
        if (a > b) {
            int delta = a / b;
            a -= delta * b;
            res += delta;
        } else {
            int delta = b / a;
            b -= delta * a;
            res += delta;
        }
        cout << a << " " << b << " : " << res << endl;
    }

    cout << res << endl;
    return 0;
}
