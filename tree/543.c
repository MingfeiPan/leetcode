/**
 * 梳理两种情况 maxpath 过root或者不过root。分别递归即可
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
    return a < b ? b : a;
}
int depth(struct TreeNode* root)
{
    if(root==NULL) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}
int diameterOfBinaryTree(struct TreeNode* root) {
    if(root==NULL) return 0;
    return max((depth(root->left)+depth(root->right)), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}
