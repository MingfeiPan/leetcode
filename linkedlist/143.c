/**
 * 三步处理完, 先用快慢指针找出中点 之后reverse后半部分节点 最后merge到一起
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* myreverse(struct ListNode* head);
void reorderList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return;
    struct ListNode *pre, *fast, *slow, *l1;
    fast = head;
    slow = head;
    l1 = head;
    while(fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    pre->next = NULL;
    struct ListNode* l2 = myreverse(slow);
    merge(l1,l2);
    
}

struct ListNode* myreverse(struct ListNode* head)
{
    struct ListNode *pre, *cur, *next;
    pre = NULL;
    cur = head;
    next = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void merge(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *t1, *t2;
    while(l1)
    {
        t1 = l1->next;
        t2 = l2->next;
        l1->next = l2;
        if(t1 == NULL) break;
        l2->next = t1;
        l1 = t1;
        l2 = t2;
    }
}

