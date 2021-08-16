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
    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return 0;
        std::stack<TreeNode*> s;
        int pre = -1, ret = INT_MAX;
        while (true) {
            while (root) {
                s.emplace(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            if (pre != -1)
                ret = std::min(ret, std::abs(pre - root->val));
            pre = root->val;
            root = root->right;
        }
        return ret;
    }
};
