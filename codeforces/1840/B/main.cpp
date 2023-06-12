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
 
static i64 Solve(const i64 n, i64 k) {
    //cout << "n=" << n << " k=" << k << endl;
    i64 i = 0, rem = n, c = 0;
    for (; i < k; ++i) {
        const i64 z = 1 << i;
        if (z <= rem) {
            rem -= z;
            ++c;
            //cout << "\ti=" << i << " z=" << z << " c=" << c << " rem=" << rem << endl;
        } else {
            break;
        }
    }
 
    int res =  1 << c;
    //cout << "\ti=" << i << " n=" << n << " rem=" << rem << " c=" << c << " res=" << res << endl;
    if ((i < k) && (n >= (1 << c))) {
        //cout << "(1)" << endl;
        //++res;
        rem = n - (1 << c);
        if (rem == 0)
            ++res;
        else if (rem > 0) {
            //cout << "(2)" << endl;
            res += Solve(rem, k);
        }
    }
    return res;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int t;
    cin >> t;
 
    for (int i = 0; i < t; ++i)
    {
        i64 n, k;
        cin >> n >> k;
        //cout << "_________________" << endl;
        cout << Solve(n, k) << endl;
    }
 
    return 0;
}
