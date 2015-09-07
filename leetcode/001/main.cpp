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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num2idx;
        int idx = 0;
        for (auto num : nums)
            num2idx[num] = ++idx;

        idx = 0;
        for (auto num : nums) {
            ++idx;
            auto it = num2idx.find(target - num);
            if (it != num2idx.end()) {
                if (it->second == idx)
                    continue;
                return {idx, it->second};
            }
        }
        return vector<int>();
    }
};

int main() {
    vector<int> nums = {3, 2 ,4};
    const int target = 6;
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    if (res.empty()) {
        cout << "No solution." << endl;
    } else {
        cout << res[0] << "\t" << res[1] << endl;
    }

    return 0;
}
