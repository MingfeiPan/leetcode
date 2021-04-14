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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small_head = new ListNode{}, *small_dummy = small_head;
        ListNode *large_head = new ListNode{}, *large_dummy = large_head;
        while (head) {
            if (head->val < x) {
                small_head->next = head;
                small_head = small_head->next;
            } else {
                large_head->next = head;
                large_head = large_head->next;
            }
            head = head->next;
        }
        large_head->next = nullptr;
        small_head->next = large_dummy->next;
        return small_dummy->next;
    }
};
