//两个node, 快慢行走 要走出来一个n的差 快的到末尾时 慢的到l-n
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode * fast = dummy;
    struct ListNode * slow = dummy;
    while(fast->next)
    {
        if(n <= 0) slow = slow->next;
        fast = fast->next; 
        n--;
    }
    if(slow->next)  slow->next = slow->next->next;
    return dummy->next;
}
