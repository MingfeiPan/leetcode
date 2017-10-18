/** 几种情况需要考虑 temp保留上个node的val, 然后接下来遇到连续两个相同可以直接跳两个, temp与当前cur->val相同,跳 * 一格, 任何两个都不符合跳一个 然后把标志位pre定到cur, 表明pre以前的node都是合条件的, 最后需要检查在cur->next
 *  为NULL跳出while的时候 检查cur->val 是否等于temp 是的话 需要删除cur节点
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode *dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = -9527;
    dummy->next = head;
    struct ListNode *cur = dummy;
    struct ListNode *pre = dummy;
    struct ListNode *next;
    int temp = 0;
    while(cur && cur->next)
    {

        if(cur->val == cur->next->val)
        {
            temp = cur->val;
            cur = cur->next->next;
            pre->next = cur;
            continue;
            
        }
        else if(temp == cur->val)
        {
            temp = cur->val;
            cur = cur->next; 
            pre->next = cur;
        }
        else
        {
            pre = cur;
            temp = cur->val;
            cur = cur->next;
        }

    }
    if(cur != NULL && cur->val == temp) pre->next = cur->next;
    return dummy->next;
    
    
    
}
