/**
 * 这里争议在要不要先求head length, 取舍两种方案其实不求是可以的 当k大于length时 fast走完一趟length就重置到head
 * 但是test case 有k特别大的情况 反而会导致tle, 所以还是要用求长度的方案
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL || k==0) return head;
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *fast = dummy, *slow = dummy, *cur;
    int len = 0;
    while(head)
    {
        head = head->next;
        len++;
    }
    while(len < k){
        k -= len;
    }
    
    while(fast->next)
    {
        if(k<=0) 
        {
            slow = slow->next;
        }
        fast = fast->next;
        k--;
    }
    
    /*while(k > 0)
    {
        if(fast->next == NULL) fast = head;
        else fast = fast->next;
        k--;
    }
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }*/
    
    cur = slow->next;
    slow->next = NULL;
    fast->next = dummy->next;
    dummy->next = cur;
    return dummy->next;
    
}
