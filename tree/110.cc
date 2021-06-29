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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        if (std::abs(left-right) > 1) {
            return false;
        } else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return std::max(left, right) + 1;
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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int left = height(root->left);
        if (left == -1)
            return -1;
        int right = height(root->right);
        if (right == -1)
            return -1;
        if (std::abs(left-right) > 1) {
            return -1;
        }
        return std::max(left, right) + 1;
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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        return isBalanced(root->left) && isBalanced(root->right) && std::abs(left - right) <= 1;
    }
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        return std::max(height(root->left), height(root->right)) + 1;
    }
};
