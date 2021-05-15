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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode *dummy = new TreeNode(), *pre;
        pre = dummy;
        std::stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (root->right)
                s.emplace(root->right);
            if (root->left)
                s.emplace(root->left);
            root->left = nullptr;
            pre->right = root;
            pre = pre->right;
        }
        root = dummy->right;
    }
};
