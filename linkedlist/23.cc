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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() >= 2) {
            int cursize = lists.size();
            for (int i = 0; i < cursize / 2; ++i) {
                lists[i] = mergeTwo(lists[i], lists[cursize-1-i]);
            }
            if (cursize % 2 == 0) {
                lists.resize(cursize / 2);
            } else {
                lists.resize(cursize / 2 + 1);
            }
        }
        return lists[0];
    }
private:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) return l2;
        if (nullptr == l2) return l1;
        ListNode* root;
        if (l1->val < l2->val) {
            root = l1;
            l1 = l1->next;
        } else {
            root = l2;
            l2 = l2->next;
        }
        ListNode* dummy = root;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                root->next = l1;
                l1 = l1->next;
            } else {
                root->next = l2;
                l2 = l2->next;
            }
            root = root->next;
        }
        if (l1) {
            root->next = l1;
        } else {
            root->next = l2;
        }
        return dummy;
    }
};
