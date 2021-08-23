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
    bool findTarget(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        s.emplace(root);
        std::unordered_map<int, int> m;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            auto iter = m.find(k-root->val);
            if (iter != m.end()) {
                return true;
            } else {
                m[root->val] = 1;
            }
            if (root->right)
                s.emplace(root->right);
            if (root->left)
                s.emplace(root->left);
        }
        return false;
    }
};
