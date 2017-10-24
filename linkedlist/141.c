/**
 * 快慢指针的完美场景
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode *fast, *slow;
    fast = head;
    slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow) return true;
    }
    return false;
}
