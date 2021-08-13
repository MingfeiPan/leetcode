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
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        int ret = root->val;
        int level = 0;
        recur(root, level, 0, ret);
        return ret;
    }
private:
    void recur(TreeNode* root, int& level, int cur_level, int& ret) {
        if (cur_level > level) {
            ret = root->val;
            level = cur_level;
        }
        if (root->left)
            recur(root->left, level, cur_level+1, ret);
        if (root->right)
            recur(root->right, level, cur_level+1, ret);
        return;
    }
};
