#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

using i64 = long long;

static void CalcEratosphenSieve(set<int>& res, int max) {
    vector<bool> sieve(2 * max, true);
    for (size_t i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) {
            res.insert(i);
            for (size_t j = i * i; j < sieve.size(); j +=i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    set<int> nums;
    CalcEratosphenSieve(nums, 1e5);
    for (auto elem : nums) {
        cout << elem << endl;
    }
    return 0;
}
