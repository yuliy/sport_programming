#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;


class Solution {
private:
    bool HasDuplicates(const string& s, int beg, int end) const {
        //cout << "beg=" << beg << '\t' << "end=" << end << endl;
        bool dict[257] = {false};
        for (int i = beg; i <= end; ++i) {
            const int chIdx = static_cast<int>(s[i]) + 128;
            if (dict[chIdx])
                return true;
            dict[chIdx] = true;
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        const int sz = s.size();
        int bestResult = 1;
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) {
                if (HasDuplicates(s, i, j))
                    break;
                bestResult = max(bestResult, j - i + 1);
            }
        }

        return bestResult;
    }
};

int main() {
    string s;
    cin >> s;

    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;;
    return 0;
}
