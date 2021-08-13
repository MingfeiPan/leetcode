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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left && !root->right) {
                delete(root);
                return nullptr;
            } else if (!root->left && root->right) {
                auto ret = root->right;
                delete(root);
                return ret;
            } else if (root->left && !root->right) {
                auto ret = root->left;
                delete(root);
                return ret;
            } else {
                auto removal = root->right;
                while (removal->left) {
                    removal = removal->left;
                }
                root->val = removal->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};

