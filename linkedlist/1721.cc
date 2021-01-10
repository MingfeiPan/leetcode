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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *begin = head, *end = head, *runner = head;
        int index = k;
        while (runner) {
            if (index <= 0) {
                end = end->next;
            }
            --index;
            if (k > 1) {
                begin = begin->next;
                --k;
            }
            runner = runner->next;
        }
        int temp = begin->val;
        begin->val = end->val;
        end->val = temp;
        return head;
    }
};
