/**
 * 分别出两条链表 一条是小于的另一条是大于等于的之后再 链起来就可以了
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL) return head;
    struct ListNode *d1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *d2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *l1 = d1;
    struct ListNode *l2 = d2;
    d1->next = NULL;
    d1->val = 0;
    d2->next = NULL;
    d2->val = 0;
    
    while(head)
    {
        if(head->val < x)
        {
            d1->next = head;
            d1 = d1->next;
        }
        else
        {
            d2->next = head;
            d2 = d2->next;
        }
        head = head->next;
    }
    //链表末尾指向NULL 很重要
    d2->next = NULL;
    d1->next = l2->next;
    return l1->next;

}
