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
    int numComponents(ListNode* head, vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int ret = 0;
        bool in = false;
        while (head) {
            auto iter = s.find(head->val);
            if (iter == s.end()) {
                if (in) {
                    ++ret;
                    in = false;
                }
            } else {
                if (!in) {
                    in = true;
                }
            }
            head = head->next;
        }
        if (in)
            ++ret;
        return ret;
    }
};
