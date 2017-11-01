/**
 * 快慢指针找到中点 reverse剩余一半 在余前一半遍历比较
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head);
bool isPalindrome(struct ListNode* head) {
    if(head == NULL) return true;
    struct ListNode *fast, *slow;
    fast = head;
    slow = head;
    while(fast)
    {
        fast = fast->next ? fast->next->next : NULL;
        slow = slow->next;
    }
    slow = reverse(slow);
    while(slow)
    {
        if(slow->val != head->val) return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
    
}

struct ListNode* reverse(struct ListNode* head)
{
    if(head == NULL) return head;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = -1;
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
