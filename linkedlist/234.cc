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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        int length = 0;
        ListNode *fast = head, *slow = head;
        while (slow) {
            ++length;
            slow = slow->next;
        }
        slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        
        ListNode *pre = new ListNode{}, *next;
        pre->next = head;
        int step = length / 2;
        while (step > 1) {
            --step;
            next = head->next;
            head->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        head->next = nullptr;
        
        head = pre->next;
        while (true) {
            if (!head && !slow)
                return true;
            if (head == slow)
                return true;
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
