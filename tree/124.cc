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
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        recur(root, ret);
        return ret;
    }
private:
    int recur(TreeNode* root, int& ret) {
        if (!root)
            return 0;
        if (ret < root->val)
            ret = root->val;
        int left = recur(root->left, ret);
        if (left < 0)
            left = 0;
        int right = recur(root->right, ret);
        if (right < 0)
            right = 0;
        if ((left + right + root->val) > ret)
            ret = left + right + root->val;
        if (left > right) {
            return left + root->val;
        } else {
            return right + root->val;
        }
    }
};
