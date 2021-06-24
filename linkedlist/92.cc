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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return head;
        if (!head->next)
            return head;
        
        ListNode *dummy = new ListNode{-1};
        dummy->next = head;
        ListNode *pre = dummy, *nxt = nullptr;
        while (left > 1) {
            pre = pre->next;
            head = head->next;
            --left;
            --right;
        }
        while (right > 1) {
            nxt = head->next;
            head->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            --right;
        }
        return dummy->next;
    }
};
