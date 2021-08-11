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
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        auto iter = memo_.find(root);
        if (iter != memo_.end())
            return iter->second;
        int rob_root = root->val;
        int not_rob_root = 0;
        if (root->left) {
            rob_root += rob(root->left->left) + rob(root->left->right);
            not_rob_root += rob(root->left);
        }
        if (root->right) {
            rob_root += rob(root->right->left) + rob(root->right->right);
            not_rob_root += rob(root->right);
        }
        int ret = std::max(rob_root, not_rob_root);
        memo_[root] = ret;
        return ret;
    }
private:
    std::unordered_map<TreeNode*, int> memo_;
};
