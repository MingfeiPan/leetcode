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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        dfs(root, "", ret);
        return ret;
    }
private:
    void dfs(TreeNode* root, std::string cur, std::vector<std::string>& ret) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            ret.emplace_back(cur+ std::to_string(root->val));
            return;
        }
        dfs(root->left, cur + std::to_string(root->val) + "->", ret);
        dfs(root->right, cur + std::to_string(root->val) + "->", ret);
        return;
    }
};
