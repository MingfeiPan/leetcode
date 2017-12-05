/**
 * preorder的第一个都是root 利用中序遍历找到root分点 之后递归前一半跟后一半就ok
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0) return NULL;
    int rootval, end;
    rootval = preorder[0];
    for(int i = 0; i < inorderSize; i++)
    {
        if(inorder[i] == rootval)
        {
            end = i;
            break;
        }
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootval;
    root->left = buildTree(preorder+1, end, inorder, end);
    root->right = buildTree(preorder+end+1, preorderSize-end-1, inorder+end+1, inorderSize-end-1);
    return root;
}
