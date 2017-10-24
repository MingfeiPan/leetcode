/**
 * 仍旧利用快慢指针, 从第一次相遇点开始慢指针与头指针同步前进直到再次相遇 就是入口点
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head ==NULL) return NULL;
    struct ListNode *fast, *slow;
    fast = head;
    slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow) break;
    }
    if(fast == NULL || fast->next ==NULL) return NULL;
    fast = head;
    while(fast)
    {
        if(fast == slow) break;
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
    
}
