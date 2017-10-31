/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = 0;
    struct ListNode *pre, *cur, *next;
    pre = dummy;
    cur = pre->next;
    while(cur->next)
    {
        next = cur->next;
        cur->next = cur->next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy->next;
}
