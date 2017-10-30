/**
 * leetcode tle 因为是bb sort所以 o(n2) 不是O(nlogn) 想O(nlogn) 要merge sort比较合适
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode *pre, *cur;
    int temp;
    pre = head;
    while(pre)
    {
        cur = head;
        while(cur->next)
        {
            if(cur->next->val < cur->val)
            {
                temp = cur->next->val;
                cur->next->val = cur->val;
                cur->val = temp;
            }
            cur = cur->next;
        }
        pre = pre->next;
    }
    return head;
}
