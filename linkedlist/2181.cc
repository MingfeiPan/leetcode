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
    ListNode* mergeNodes(ListNode* head) {
        int cur = 0;
        ListNode* dummy = head, *pre = head;
        head = head->next;
        while (head) {
            if (head->val > 0) {
                cur += head->val;
                head = head->next; 
            } else {
                head->val = cur;
                cur = 0;
                pre->next = head;
                pre = head;
                head = head->next;
            }
        }
        return dummy->next;
    }
};
