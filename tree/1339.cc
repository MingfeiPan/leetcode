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
    int maxProduct(TreeNode* root) {
        recur(root);
        sum(root);
        return ret_ % (int)(1e9 + 7);
    }
private:
    int64_t sum(TreeNode* root) {
        if (!root)
            return 0;
        int64_t cur = sum(root->left) + root->val + sum(root->right);
        ret_ = std::max(ret_, cur * (total_ - cur));
        return cur;
    }
    void recur(TreeNode* root) {
        if (!root)
            return;
        recur(root->left);
        total_ += root->val;
        recur(root->right);
    } 
    int64_t total_ = 0;
    int64_t ret_ = 0;
    
};
