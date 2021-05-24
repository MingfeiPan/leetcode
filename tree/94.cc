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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        if (!root)
            return ret;
        std::stack<TreeNode*> s;
        while (true) {
            while (root) {
                s.emplace(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            ret.emplace_back(root->val);
            root = root->right;
        }
        return ret;
    }
};
