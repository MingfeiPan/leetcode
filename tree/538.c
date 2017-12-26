/**
 * encounter a problem when submitting in leetcode, but quite sure the answer is right
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sum = 0;

void convertB(struct TreeNode* root)
{
    if(root == NULL) return;
    convertB(root->right);
    sum += root->val;
    root->val = sum;
    convertB(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    convertB(root);
    return root;
}
