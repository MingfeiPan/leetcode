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
struct Item {
    int level;
    TreeNode* root;
};
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ret;
        if (!root)
            return ret;
        std::queue<Item> q;
        q.emplace(Item{0, root});
        int pre_level = 0;
        int pre_value = root->val;
        while (!q.empty()) {
            Item i = q.front();
            q.pop();
            if (i.level != pre_level) {
                ret.emplace_back(pre_value);
                pre_level = i.level;
            }
            pre_value = i.root->val;
            if (i.root->left) {
                q.emplace(Item{i.level+1, i.root->left});
            }
            if (i.root->right) {
                q.emplace(Item{i.level+1, i.root->right});
            }
        }
        ret.emplace_back(pre_value);
        return ret;
    }
};
