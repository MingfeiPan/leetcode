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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        recur(root, sum, 0);
        return sum;
    }
private:
    void recur(TreeNode* root, int& sum, int cur) {
        if (!root->left && !root->right) {
            sum += cur*10 + root->val;
            return;
        }
        if (root->left)
            recur(root->left, sum, cur*10+root->val);
        if (root->right)
            recur(root->right, sum, cur*10+root->val);
    }
};
