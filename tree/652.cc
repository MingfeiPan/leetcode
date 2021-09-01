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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        std::vector<TreeNode*> ret;
        for (auto iter = m_.begin(); iter != m_.end(); ++iter) {
            if (iter->second.size() > 1)
                ret.emplace_back(std::move(iter->second[0]));
        }
        return ret;
    }
private:
    std::unordered_map<std::string, std::vector<TreeNode*>> m_;
    std::string serialize(TreeNode* root) {
        if (!root)
            return "";
        std::string cur = "(" + serialize(root->left) + std::to_string(root->val) + serialize(root->right) + ")";
        m_[cur].emplace_back(std::move(root));
        return cur;
    }
};
