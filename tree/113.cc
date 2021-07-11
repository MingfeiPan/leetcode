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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> ret;
        if (!root)
            return ret;
        std::vector<int> cur_list;
        int cur = 0;
        dfs(root, ret, cur_list, cur, targetSum);
        return ret;
    }
private:
    void dfs(TreeNode* root, std::vector<std::vector<int>>& ret, std::vector<int>& cur_list, int& cur, int target) {
        if (!root->left && !root->right && (cur + root->val) == target) {
            cur_list.emplace_back(root->val);
            ret.emplace_back(cur_list);
            cur_list.pop_back();
            return;
        }
        if (root->left) {
            cur_list.emplace_back(root->val);
            cur += root->val;
            dfs(root->left, ret, cur_list, cur, target);
            cur_list.pop_back();
            cur -= root->val;
        }
        if (root->right) {
            cur_list.emplace_back(root->val);
            cur += root->val;
            dfs(root->right, ret, cur_list, cur, target);
            cur_list.pop_back();
            cur -= root->val;
        }        
    }
};
