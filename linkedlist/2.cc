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
        ListNode* dummy = new ListNode(), *head = dummy;
        int flag = 0;
        while (l1 || l2) {
            int i1 = l1 ? l1->val : 0;
            int i2 = l2 ? l2->val : 0;
            int cur = i1 + i2 + flag;
            flag = cur / 10;
            cur = cur % 10;
            head->next = new ListNode(cur);
            head = head->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (flag) head->next = new ListNode(flag);
        return dummy->next;
    }
};
