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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        if (!root)
            return ret;
        std::stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            ret.emplace_back(root->val);
            if (root->right)
                s.emplace(root->right);
            if (root->left)
                s.emplace(root->left);
        }
        return ret;
        
    }
};
