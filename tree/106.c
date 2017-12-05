/**
 * 注意后序跟前序的区别 在截取right part时 postorder比inorder少1
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(postorderSize == 0) return NULL;
    int rootval;
    int end = 0;
    rootval = postorder[postorderSize-1];
    while(rootval != inorder[end]) ++end;
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootval;
    root->left = buildTree(inorder, end, postorder, end);
    root->right = buildTree(inorder+end+1, inorderSize-end-1, postorder+end, postorderSize-end-1);
    return root;
}
