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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_set<int> root_set;
        std::unordered_map<int, TreeNode*> node_map;        
        for (const auto& des : descriptions) {
            if (!node_map.count(des[0])) node_map[des[0]] = new TreeNode(des[0]);
            if (!node_map.count(des[1])) node_map[des[1]] = new TreeNode(des[1]);
            root_set.emplace(des[1]);
            TreeNode* parent = node_map[des[0]], *child = node_map[des[1]];
            if (des[2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        for (const auto& node : node_map) {
            if (!root_set.count(node.first)) return node.second;
        }
        return nullptr;
    }
};
