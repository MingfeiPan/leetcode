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
    vector<int> postorderTraversal(TreeNode* root) {
        recur(root);
        return ret_;
    }
private:
    std::vector<int> ret_;
    void recur(TreeNode* root) {
        if (!root)
            return;
        recur(root->left);
        recur(root->right);
        ret_.emplace_back(root->val);
    }
};
