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
        if (!head) return nullptr;
        ListNode* tail = head;
        int count = 1;
        while (tail->next) {
            tail = tail->next;
            ++count;
        }
        if (k % count == 0) return head;
        k = k % count;
        k = count - k;
        ListNode* pre = head;
        while (k > 1) {
            pre = pre->next;
            --k;
        }
        ListNode* new_head = pre->next;
        tail->next = head;
        pre->next = nullptr;
        return new_head;
    }
};
