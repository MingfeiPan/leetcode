/**
 * 比较cur跟cur->next, 如果相同就删除cur, 保持pre在cur之前即可
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL) return head;
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -9527;
    dummy->next = head;
    struct ListNode *cur, *pre;
    cur = head;
    pre = dummy;
    while(cur && cur->next)
    {
        if(cur->next->val == cur->val)
        {
            pre->next = cur->next;
            cur = cur->next;
        }
        else
        {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return dummy->next;
}
