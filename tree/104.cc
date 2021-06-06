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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ret = 0, cur = 1;
        recur(root, ret, cur);
        return ret;
    }
private:
    void recur(TreeNode* root, int& ret, int& cur) {
        if (!root->left && !root->right) {
            ret = max(ret, cur);
        }
        if (root->left) {
            ++cur;
            recur(root->left, ret, cur);
            --cur;
        }
        if (root->right) {
            ++cur;
            recur(root->right, ret, cur);
            --cur;
        }
    }
};

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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
