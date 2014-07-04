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
#include <cmath>
using namespace std;

int main() {
    int k, n;
    cin >> n >> k;
    const int pairs_cnt = n / 2;
    if (k < pairs_cnt) {
        cout << "-1" << endl;
        return 0;
    }

    /*
    int num = 1;
    for (int i = 1; i < pairs_cnt; ++i) {
        cout << num << " ";
        num = GetNextNum(num);
        cout << num << " ";
        num = GetNextNum(num);
    }
    for (int i = 1; i < pairs_cnt; ++i)
        cout << "1 1 ";
    int tmp = k - pairs_cnt + 1;
    cout << tmp << " " << tmp << " ";
    if (1 == n % 2)
        cout << "1" << endl;
    */

    return 0;
}
