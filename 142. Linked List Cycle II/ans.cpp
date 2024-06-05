/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (true) {
            if (p1 == nullptr || p2 == nullptr || p2->next == nullptr)
                return nullptr;
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                break;
        }
        ListNode *pN = head;
        // move pN forward for loop-length times.
        while (true) {
            p2 = p2->next;
            pN = pN->next;
            if (p1 == p2)
                break;
        }
        p1 = head;
        while (p1 != pN) {
            p1 = p1->next;
            pN = pN->next;
        }
        return p1;
    }
};
