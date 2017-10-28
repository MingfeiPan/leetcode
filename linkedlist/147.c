/**
 * 让dummy 成为一个新linked list的start 而不是作为原来head的前置dummy是tricky part
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    dummy->val = -9527;
    struct ListNode *next, *cur, *temp;
    cur = head;
    temp = dummy;
    next = NULL;
    while(cur)
    {
        next = cur->next;
        while(temp->next != NULL && temp->next->val <= cur->val)
        {
            temp = temp->next;
        }
        cur->next = temp->next;
        temp->next = cur;
        cur = next;
        temp = dummy;
    }
    return dummy->next;
}
