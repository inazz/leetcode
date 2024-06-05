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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode **next_holder = &l1;
        int val = 0;
        while (!(p1 == nullptr && p2 == nullptr && val == 0)) {
            if (p2 != nullptr) {
                val += p2->val;
                p2 = p2->next;
            }
            if (p1 == nullptr) {
                (*next_holder) = p1 = new ListNode(0);
            }
            val += p1->val;
            p1->val = val % 10;
            val /= 10;
            next_holder = &(p1->next);
            p1 = p1->next;
        }
        return l1;
    }
};
