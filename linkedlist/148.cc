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
    ListNode* sortList(ListNode* head) {
        ListNode *dummy = new ListNode{};
        ListNode *cur, *pre, *temp;
        while (head) {
            pre = dummy;
            cur = dummy->next;
            while (cur) {
                if (head->val < cur->val)
                    break;
                pre = pre->next;
                cur = cur->next;
            }
            temp = head;
            head = head->next;
            pre->next = temp;
            temp->next = cur;
        }
        return dummy->next;
    }
};
