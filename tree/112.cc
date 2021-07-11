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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        dfs(root, 0, targetSum);
        return flag_;
    }
private:
    bool flag_ = false;
    void dfs(TreeNode* root, int cur, int targetSum) {
        if (flag_)
            return;
        if (!root->left && !root->right && (cur + root->val) == targetSum) {
            flag_ = true;
            return;
        }
        if (root->left)
            dfs(root->left, cur + root->val, targetSum);
        if (root->right)
            dfs(root->right, cur + root->val, targetSum);
    }
};
