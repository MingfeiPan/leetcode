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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        std::stack<TreeNode*> s;
        bool init = false;
        int pre = 0;
        while (true) {
            while (root) {
                s.emplace(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            if (!init) {
                pre = root->val;
                init = true;
            } else {
                if (pre >= root->val) {
                    return false;
                }
                pre = root->val;
            }
            root = root->right;
        }
        return true;
    }
};
