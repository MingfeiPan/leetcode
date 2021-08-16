/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
X *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int Xx, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return ret_;
        recur(root, 0);
        return ret_;
    }
private:
    void recur(TreeNode* root, int level) {
        if (!root)
            return;
        if (ret_.size() == level) {
            ret_.emplace_back(root->val);
        }
        ret_[level] = std::max(ret_[level], root->val);
        recur(root->left, level+1);
        recur(root->right, level+1);
        return;
    }
    std::vector<int> ret_;
};
