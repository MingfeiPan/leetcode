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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;
        int length = 0;
        ListNode *dummy = head, *dummyhead = head, *tail = head;
        while (dummy) {
            dummy = dummy->next;
            length++;
        }
        dummy = head;
        if (k > length) {
            k = k % length;    
        }    
        while (k > 0) {
            head = head->next;
            k--;
        }        
        while (head && head->next) {
            head = head->next;
            tail = tail->next;
        }
        if (!head) {
            return dummy;
        }
        head->next = dummy;
        dummy = tail->next;
        tail->next = nullptr;
        return dummy;
    }
};
