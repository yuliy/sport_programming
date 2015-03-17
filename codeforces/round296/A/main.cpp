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

long long gcd(long long a, long long b) {
    long long res = 0;
    while ( a != 0 ) {
        long long c;
        c = a;
        res += b / a;
        a = b % a;
        b = c;
    }
    //return b;
    return res;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
