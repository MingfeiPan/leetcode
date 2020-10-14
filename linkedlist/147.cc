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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode{};
        ListNode* pre, *cur, *temp;
        while (head) {
            pre = dummy;
            cur = dummy->next;
            while (cur) {
                if (head->val < cur->val)
                    break;
                pre = pre->next;
                cur = cur->next;
            }
            temp = head->next;
            pre->next = head;
            head->next = cur;
            head = temp;
        }
        return dummy->next;
    }
};
