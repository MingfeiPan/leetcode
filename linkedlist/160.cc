/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        while (lenA > lenB) {
            headA = headA->next;
            --lenA;
        }
        while (lenB > lenA) {
            headB = headB->next;
            --lenB;
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
private:
    int getLen(ListNode *head) {
        int length = 0;
        while (head) {
            head = head->next;
            ++length;
        }
        return length;
    }
};
