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
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        recur(root, root->val);
        return ret_;
    }
private:
    void recur(TreeNode* root, int cur_max) {
        if (!root)
            return;
        if (root->val >= cur_max)
            ++ret_;
        cur_max = std::max(cur_max, root->val);
        recur(root->left, cur_max);
        recur(root->right, cur_max);
        return;
    }
    int ret_;
};
