/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root)
            return ret_;
        recur(root);
        int count = 0, ret = 0;
        for (auto iter = m_.begin(); iter != m_.end(); ++iter) {
            count = std::max(count, iter->second);
        }
        for (auto iter = m_.begin(); iter != m_.end(); ++iter) {
            if (iter->second == count) {
                ret_.emplace_back(iter->first);
            }
        }
        return ret_;
    }
private:
    std::unordered_map<int, int> m_;
    std::vector<int> ret_;
    int recur(TreeNode* root) {
        if (!root)
            return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        int sum = root->val + left + right;
        ++m_[sum];
        return sum;
    }
};
