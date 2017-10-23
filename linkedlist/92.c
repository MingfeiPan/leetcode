/**
 * reverse的思路就是找到开始点cur, cur前一个pre, cur后一个next, 把每一个新的next接到pre后面知道cur->next为NULL
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(n==m) return head;
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = -9527;
    struct ListNode *pre, *cur, *next;
    pre = dummy;
    n -= m;
    while(m > 1)
    {
        pre = pre->next;
        m--;
    }
    cur = pre->next;
    while(n > 0)
    {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        n--;
    }
    return dummy->next;
    

    
}
