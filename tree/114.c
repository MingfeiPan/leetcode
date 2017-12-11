/**
 * 注意left 要置为NULL
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(root == NULL) return;
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    root->left = NULL;
    flatten(left);
    flatten(right);
    root->right = left;
    struct TreeNode* cur = root;
    while(cur->right != NULL) cur = cur->right;
    cur->right = right;
}
