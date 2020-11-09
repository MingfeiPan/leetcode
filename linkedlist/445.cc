/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<ListNode*> s1;
        std::stack<ListNode*> s2;
        while (l1) {
            s1.emplace(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.emplace(l2);
            l2 = l2->next;
        }
        int flag = 0, n1, n2, sum;
        ListNode* dummy = nullptr;
        while (!s1.empty() || !s2.empty() || flag > 0) {
            if (!s1.empty()) {
                n1 = s1.top()->val;
                s1.pop();
            }else {
                n1 = 0;
            }
            if (!s2.empty()) {
                n2 = s2.top()->val;
                s2.pop();
            } else {
                n2 = 0;
            }
            sum = n1 + n2 + flag;
            ListNode* newnode = new ListNode{sum % 10};
            newnode->next = dummy;
            dummy = newnode;
            flag = sum / 10;
        }
        return dummy;
    }
};
