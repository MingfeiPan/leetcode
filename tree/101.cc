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
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }
private:
    bool isSym(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (left && right)
            return left->val == right->val && isSym(left->left, right->right) && isSym(left->right, right->left);
        return false;
    }
};
