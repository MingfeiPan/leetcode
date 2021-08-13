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
    vector<int> findMode(TreeNode* root) {
        std::stack<TreeNode*> s;
        std::unordered_map<int, int> m;
        while (true) {
            while (root) {
                s.emplace(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            ++m[root->val];
            root = root->right;
        }
        int max_count = 0;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second > max_count)
                max_count = iter->second;
        }
        std::vector<int> ret;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second == max_count) {
                ret.emplace_back(iter->first);
            }
        }
        return ret;
    }
};
