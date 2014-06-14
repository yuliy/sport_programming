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
    int a;
    string s;
    cin >> a >> s;
    const int N = s.size();
    vector<int> ps(s.size() + 1);
    ps[0] = 0;
    for (int i = 1; i <= N; ++i) {
        ps[i] = ps[i-1] + int(s[i-1] - '0');
    }

    int zero_cnt = 0;
    map<int, int> divisors;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            const int sum_ij = ps[j] - ps[i-1];
            if (0 == sum_ij) {
                ++zero_cnt;
                continue;
            }

            if (0 == a % sum_ij)
                ++divisors[sum_ij];
        }
    }

    if (0 == a) {
        cout << (N * (N+1) * zero_cnt - zero_cnt) << endl;
        return 0;
    }

    int res = 0;
    for (auto iter = divisors.begin(); iter != divisors.end(); ++iter) {
        const int divisor = iter->first;
        const int cnt = iter->second;
        const int supplementDivisor = a / divisor;
        auto citer = divisors.find(supplementDivisor);
        if (citer != divisors.end()) {
            res += (cnt * citer->second);
        }
    }

    cout << res << endl;
    return 0;
}
