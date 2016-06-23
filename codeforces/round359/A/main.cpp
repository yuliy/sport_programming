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
    long long n, x;
    cin >> n >> x;
    int sad = 0;
    for (int i = 0; i < n; ++i) {
        char sign;
        long long d;
        cin >> sign >> d;
        if (sign == '+') {
            x += d;
        } else {
            if (x >= d) {
                x -= d;
            } else {
                ++sad;
            }
        }
    }
    cout << x << ' ' << sad << endl;
    return 0;
}
