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
    TreeNode *root;
    int level;
};
public:
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ret;
        if (!root)
            return ret;
        
        std::queue<Item> q;
        q.emplace(Item{root, 0});
        int level = 0;
        double sum = 0.0;
        int total = 0;
        while (!q.empty()) {
            Item i = q.front();
            q.pop();            
            if (i.level != level) {
                ret.emplace_back(sum / total);
                sum = 0;
                total = 0;
                level = i.level;
            }
            sum += i.root->val;
            ++total;            
            if (i.root->left) {
                q.emplace(Item{i.root->left, i.level+1});
            }
            if (i.root->right) {
                q.emplace(Item{i.root->right, i.level+1});
            }
        }
        if (total != 0) {
            ret.emplace_back(sum / total);
        }
        return ret;
        
    }
};
