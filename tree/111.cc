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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ret = INT_MAX;
        dfs(root, ret, 0);
        return ret;
    }
    void dfs(TreeNode* root, int& ret, int cur) {
        if (!root->left && !root->right) {
            if ((cur+1) < ret) {
                ret = cur + 1;
            }
        }
        if (root->left)
            dfs(root->left, ret, cur+1);
        if (root->right)
            dfs(root->right, ret, cur+1);
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ret = INT_MAX;
        dfs(root, ret, 0);
        return ret;
    }
    void dfs(TreeNode* root, int& ret, int cur) {
        if (!root->left && !root->right) {
            if ((cur+1) < ret) {
                ret = cur + 1;
            }
        }
        if (root->left)
            dfs(root->left, ret, cur+1);
        if (root->right)
            dfs(root->right, ret, cur+1);
    }
};
