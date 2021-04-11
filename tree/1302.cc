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
    TreeNode *root;
};
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root)
            return 0;
        std::queue<Item> q;
        q.emplace(Item{1, root});
        
        int index = 0, cur = 0;
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            if (i.level != index) {
                index = i.level;
                cur = i.root->val;
            } else {
                cur += i.root->val;              
            }
            if (i.root->left)
                q.emplace(Item{i.level+1, i.root->left});
            if (i.root->right)
                q.emplace(Item{i.level+1, i.root->right});              
            
        }
        return cur;
    }
};
