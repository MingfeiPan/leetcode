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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        return pathSumFrom(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
private:
    int pathSumFrom(TreeNode* root, int target) {
        if (!root)
            return 0;
        int ret = 0;
        if (root->val == target)
            ret = 1;
        return ret + pathSumFrom(root->left, target - root->val) + pathSumFrom(root->right, target - root->val);
    }
};
