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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret = 0;
        recur(root, ret, low, high);
        return ret;
    }
private:
    void recur(TreeNode* root, int& ret, int& low, int& high) {
        if (!root)
            return;
        if (root->val >= low && root->val <= high) {
            ret += root->val;
        }
        if (root->val > low)
            recur(root->left, ret, low, high);
        if (root->val < high)
            recur(root->right, ret, low, high);
    }
};
