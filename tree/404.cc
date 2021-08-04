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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        dfs(root->left, 0, &sum);
        dfs(root->right, 1, &sum);
        return sum;
    }
private:
    void dfs(TreeNode* root, int dir, int* sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right && dir == 0) {
            *sum += root->val;
        }
        dfs(root->left, 0, sum);
        dfs(root->right, 1, sum);
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        int ret = 0;
        recur(root, ret, 0);
        return ret;
    }
private:
    void recur(TreeNode* root, int& ret, int flag) {
        if (!root->left && !root->right && flag == 1) {
            ret += root->val;
            return;
        }
        if (root->left)
            recur(root->left, ret, 1);
        if (root->right)
            recur(root->right, ret, 0);
    }
};
