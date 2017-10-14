/* 这里仔细观察了过程, 可以发现交换一对pair 实际上可以看做另一个过程
 * 就是先设置一个dummy node 然后看开始4个node dummy->1->2->3 实际上是在这四个节点中 交换1跟2的位置, 这样把
 * dummy跟3 两个节点一起加进来做为一组考虑 可以方便的删除新增节点 不至于让头尾断掉
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dump = dummy;
    struct ListNode *temp = NULL;
    dummy->val = 0;
    dummy->next = head;
    while(dummy && dummy->next)
    {
        if(dummy->next->next)
        {
            temp = dummy->next;
            dummy->next = temp->next;
            temp->next = dummy->next->next;
            dummy->next->next = temp;
        }
        dummy = dummy->next->next;
    }
    return dump->next;
    
}
