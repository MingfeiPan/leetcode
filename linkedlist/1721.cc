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
        ListNode *first = head, *pre = head;
        while (k > 0) {
            --k;
            pre = pre->next;
            if (k == 0)
                break;
            first = first->next;
        }
        ListNode* second = head;
        while (pre) {
            pre = pre->next;
            second = second->next;
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return head;
    }
};

