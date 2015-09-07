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

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        const ui64 num1 = List2Num(l1);
        const ui64 num2 = List2Num(l2);
        return Num2List(num1 + num2);
    }
private:
    using ui64 = unsigned long long;

    ui64 List2Num(const ListNode* node) {
        ui64 res = 0;
        for (ui64 mult = 1; node; node = node->next, mult *= 10) {
            res += (mult * node->val);
        }
        return res;
    }

    ListNode* Num2List(ui64 num) {
        vector<int> digits;
        if (num) {
            for (; num; num /= 10)
                digits.push_back(num % 10);
        } else {
            digits.push_back(0);
        }
        reverse(digits.begin(), digits.end());

        ListNode* node = new ListNode(digits.front());
        for (size_t i = 1; i < digits.size(); ++i) {
            ListNode* newNode = new ListNode(digits[i]);
            newNode->next = node;
            node = newNode;
        }
        return node;
    }
};

int main() {

    return 0;
}
