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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode{}, *newhead = dummy;
        std::stack<TreeNode*> s_;
        while (true) {
            while (root) {
                s_.emplace(root);
                root = root->left;
            }
            if (s_.empty())
                break;
            root = s_.top();
            s_.pop();
            TreeNode *cur = new TreeNode{root->val};
            dummy->right = cur;
            dummy = cur;            
            root = root->right;
        }
        return newhead->right;
    }
};
