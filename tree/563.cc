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
    int findTilt(TreeNode* root) {
        int ret = 0;
        recur(root, ret);
        return ret;
    }
private:
    int recur(TreeNode* root, int& ret) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        int left = recur(root->left, ret);
        int right = recur(root->right, ret);
        ret += abs(left - right);
        return left + right + root->val;
    }
};
