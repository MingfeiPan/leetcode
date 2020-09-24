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
    int longestUnivaluePath(TreeNode* root) {
        ret = 0;
        recur(root);
        return ret;
    }
    
private:
    int ret;
    int recur(TreeNode* root) {
        if (!root)
            return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        if (root->left && root->left->val == root->val) {
            left = left + 1;
        } else {
            left = 0;
        }
        if (root->right && root->right->val == root->val) {
            right = right + 1;
        } else {
            right = 0;
        }
        ret = max(ret, left+right);
        return max(left, right);
    }
};
