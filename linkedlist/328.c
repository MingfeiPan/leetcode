/**
 * 分离odd跟even list 然后再拼接起来
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *odd, *even, *l1, *l2;
    odd = head;
    even = head->next;
    l1 = odd;
    l2 = even;
    head = head->next->next;
    int i = 1;
    while(head)
    {
        if(i > 0)
        {
            odd->next = head;
            odd = odd->next;
            head = head->next;  
        }
        else
        {
            even->next = head;
            even = even->next;
            head = head->next;
        }
        i = i * -1;
    }

    even->next = NULL;
    odd->next = l2;
    return l1;
    
}
