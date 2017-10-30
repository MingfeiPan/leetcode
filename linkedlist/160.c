/**
 * tricky part 是遍历的时候 两个head分别走完自己的长度之后再指向对方的head继续走 就可以相遇在intersection 如果没有intersection 则相遇在null
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    struct ListNode *a, *b;
    a = headA;
    b = headB;
    while(a != b)
    {
        if(a) a = a->next; 
        else a = headB;
        if(b) b = b->next; 
        else b = headA;
    }
    return a;
}
