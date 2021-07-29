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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode *leftNode = root->left, *rightNode = root->right;
        int left = 0, right = 0;
        while (leftNode) {
            ++left;
            leftNode = leftNode->left;
        }
        
        while (rightNode) {
            ++right;
            rightNode = rightNode->right;
        }
        
        if (left == right) {
            return std::pow(2, left+1)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
