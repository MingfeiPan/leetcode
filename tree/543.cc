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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        ret = std::max(ret, recur(root));
        return ret-1;
    }
private:
    int recur(TreeNode* root) {
        if (!root)
            return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        ret = std::max(ret, left + right + 1);
        return std::max(left, right) + 1;
    }
    int ret = 0;
};
