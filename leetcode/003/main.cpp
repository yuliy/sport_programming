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
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        const int sz = s.size();
        unordered_map<char, int> char2cnt;
        char2cnt[s[0]] = 1;
        int beg = 0;
        int end = 1;

        int bestResult = 1;
        for (;;) {
            while (0 == char2cnt[ s[end] ] && end < sz) {
                char2cnt[ s[end] ] += 1;
                ++end;
            }
            bestResult = max(bestResult, end-beg);

            while (0 != char2cnt[ s[beg] ]) {
                char2cnt[ s[beg] ] -= 1;
                ++beg;
            }
        }

        return bestResult;
    }
};

int main() {
    string s;
    cin >> s;

    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
