/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    using TPair = std::pair<ListNode*, ListNode*>;

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;

        TPair pair = make_pair(nullptr, head);
        ListNode* newHead = (head->next != nullptr) ? head->next : head;
        while (pair.second != nullptr)
            pair = swapPair(pair.first, pair.second);

        return newHead;
    }

private:
    // We have this configuration:
    //   a -> b -> c -> d
    // This function swaps b and c. And returns new a and b (that is b and d).
    TPair swapPair(ListNode* a, ListNode* b) {
        ListNode* c = b->next;
        if (c == nullptr)
            return make_pair(nullptr, nullptr);

        ListNode* d = c->next;

        if (a != nullptr)
            a->next = c;
        b->next = d;
        c->next = b;

        return make_pair(b, d);
    }
};
