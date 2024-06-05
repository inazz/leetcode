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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        ListNode **next_holder = &head;
        while (p != nullptr) {
            if (p->next != nullptr && p->val == p->next->val) {
                int val = p->val;
                while (p != nullptr && p->val == val)
                    p = p->next;
                *next_holder = p;
            } else {
                next_holder = &(p->next);
                p = p->next;
            }
        }
        return head;
    }
};
