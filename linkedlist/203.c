/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *cur, *pre;
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = -9527;
    cur = head;
    pre = dummy;
    while(cur)
    {
        if(cur->val == val)
        {
            pre->next = cur->next;
            cur = cur->next;
        }
        else
        {
            pre = pre->next;    
            cur = cur->next;
        }
    }
    return dummy->next;
}
