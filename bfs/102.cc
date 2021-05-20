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
struct Item {
    TreeNode *root;
    int level;
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if (!root)
            return ret;
        std::queue<Item> q;
        q.emplace(Item{root, 0});
        int index = 0;
        std::vector<int> cur;
        while (!q.empty()) {
            Item item = q.front();
            q.pop();
            if (item.level != index) {
                ++index;
                std::vector<int> temp;
                cur.swap(temp);
                ret.emplace_back(std::move(temp));
            }
            cur.emplace_back(item.root->val);
            if (item.root->left) {
                q.emplace(Item{item.root->left, item.level+1});
            }
            if (item.root->right) {
                q.emplace(Item{item.root->right, item.level+1});
            }
        }
        ret.emplace_back(std::move(cur));
        return ret;
    }
};
