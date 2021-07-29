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
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        std::stack<TreeNode*> s;
        while (true) {
            while (root) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (k == 1)
                return root->val;
            --k;
            root = root->right;
        }
        return 0;
    }
};
