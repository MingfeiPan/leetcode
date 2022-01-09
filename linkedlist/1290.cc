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
    int getDecimalValue(ListNode* head) {
        std::vector<int> v;
        while (head) {
            v.emplace_back(head->val);
            head = head->next;
        }
        int ret = 0, index = 1;
        for (int i = 0; i < v.size(); ++i) {
            ret += v[v.size()-i-1] * index;
            index *= 2;
        }
        return ret;
    }
};

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
    int getDecimalValue(ListNode* head) {
        std::vector<int> nums;
        nums.reserve(30);
        while (head) {
            nums.emplace_back(head->val);
            head = head->next;
        }
        int mul = 1;
        int ret = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
            ret += mul * nums[i];
            mul *= 2;
        }
        return ret;
    }
};
