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
    TreeNode* root;
    int64_t level;
    int64_t pos;
};
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        std::queue<Item> q;
        q.emplace(Item{root, 0, 1});
        int64_t curlevel = 0, curpos = 1, ret = 0, MOD = 2147483649;
        while (!q.empty()) {
            auto item = q.front();
            q.pop();
            if (item.level != curlevel) {
                curlevel = item.level;
                curpos = item.pos;
            } else {
                ret = std::max(ret, item.pos - curpos + 1);
            }
            if (item.root->left)
                q.emplace(Item{item.root->left, item.level+1, item.pos*2 % MOD});
            if (item.root->right)
                q.emplace(Item{item.root->right, item.level+1, (item.pos*2+1) % MOD});
        }
        return ret;
    }
};
