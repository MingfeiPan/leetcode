/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumN(struct TreeNode* root, int sum)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return sum*10+root->val;
    return sumN(root->left, sum*10+root->val) + sumN(root->right, sum*10+root->val);
}
int sumNumbers(struct TreeNode* root) {
    return sumN(root, 0);
}
