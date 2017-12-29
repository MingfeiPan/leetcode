/**
 * 按照L, R的边界条件 分别递归...
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if(root==NULL) return NULL;
    if(root->val < L) return trimBST(root->right, L, R);
    if(R < root->val) return trimBST(root->left, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}
