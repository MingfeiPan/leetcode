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
        ListNode* dummy = new ListNode(), *pre = dummy;
        dummy->next = head;
        bool in = false;
        while (head && head->next) {
            if (in) {
                if (head->val != head->next->val) {
                    pre->next = head->next;
                    in = false;
                }
                head = head->next;
            } else {
                if (head->val == head->next->val) {
                    in = true;
                } else {
                    pre = pre->next;   
                }
                head = head->next;
            }
        }
        if (in) pre->next = nullptr;
        return dummy->next;
        
    }
};
