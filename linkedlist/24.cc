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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode{}, *pre, *nxt;
        dummy->next = head;
        pre = dummy;
        while (head && head->next) {
            nxt = head->next;
            pre->next = nxt;
            head->next = nxt->next;
            nxt->next = head;
            head = head->next;
            pre = pre->next->next;
        }
        return dummy->next;
    }
};
