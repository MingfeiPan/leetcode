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
        if (!head || !head->next) return head;
        ListNode* mid = findMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1)
            head->next = l1;
        if (l2)
            head->next = l2;
        return dummy->next;
    }
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *temp;
        while (head && head->next) {
            temp = slow;
            slow = slow->next;
            head = head->next->next;
        }
        if (slow == head) return slow;
        temp->next = nullptr;
        return slow;
    }
};
