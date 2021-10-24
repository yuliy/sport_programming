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

    int n;
    cin >> n;

    int evenIdx = -1;
    int oddIdx = -1;
    int evenCnt = 0;
    int oddCnt = 0;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        if (num & 1) {
            oddIdx = i;
            ++oddCnt;
        } else {
            evenIdx = i;
            ++evenCnt;
        }
    }

    const int res = (evenCnt == 1) ? evenIdx : oddIdx;
    cout << res << endl;

    return 0;
}
