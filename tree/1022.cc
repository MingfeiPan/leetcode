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
    int sumRootToLeaf(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        std::vector<int> cur;
        dfs(root, cur);
        for (auto it = queue_.begin(); it != queue_.end(); it++) {
            sum += getsum(*it);
        }
        return sum;
    }
private:
    std::vector<std::vector<int>> queue_;
    void dfs(TreeNode* root, std::vector<int> cur) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            cur.push_back(root->val);
            queue_.push_back(cur);
            return;
        }else {
            cur.push_back(root->val);
            dfs(root->left, cur);
            dfs(root->right, cur);            
        }
    }
    int getsum(std::vector<int> nums) {
        int ret = 0;
        int step = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            ret += nums[i] * step;
            step *= 2;
        }
        return ret;
    }
};
