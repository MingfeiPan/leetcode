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
    int pseudoPalindromicPaths (TreeNode* root) {
        std::vector<int> cur;
        int ret = 0;
        recur (root, cur, ret);
        return ret;
    }
private:
    void recur(TreeNode* root, std::vector<int> cur, int& ret) {
        if (!root->left && !root->right) {
            cur.emplace_back(root->val);
            if (check(cur))
                ++ret;
            return;
        }
        cur.emplace_back(root->val);
        if (root->left)
            recur(root->left, cur, ret);
        if (root->right)
            recur(root->right, cur, ret);
    }
    bool check(std::vector<int> cur) {

        std::unordered_map<int, int> m;
        for (const auto& i : cur) {
            auto iter = m.find(i);
            if (iter != m.end()) {
                ++iter->second;
            } else {
                m.emplace(i, 1);
            }
        }
       
        int count = 0;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second % 2 != 0)
                ++count;
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};
