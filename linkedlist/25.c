/* 从上一题扩展 实际上还是3个节点的交换位置问题 多出来的节点可以看作第三个节点的后续部分, 而看成一个整体
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head==NULL || k == 1) return head;
    struct ListNode* dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    int num = 0;
    struct ListNode *cur = dummy, *pre = dummy, *next;
    while(cur = cur->next)
    {
        num++;
    }
    while(num >= k)
    {
        cur = pre->next;
        next = cur->next;
        for(int i = 1; i < k;i++)
        {
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = cur->next;
        }
        pre = cur;
        num -= k;
    }
    return dummy->next;
    
    
    
}
 
