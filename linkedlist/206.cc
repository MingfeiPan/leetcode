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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode{-1};
        dummy->next = head;
        ListNode *pre = dummy, *nxt = nullptr;
        while (head && head->next) {
            nxt = head->next;
            head->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};
