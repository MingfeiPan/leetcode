/**
 * dfs use -1 to show when the node is unbalanced, then go recursive 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int checkBalance(struct TreeNode* root)
{
    if(root==NULL) return 0;
    int leftheight = checkBalance(root->left);
    if(leftheight == -1) return -1;
    int rightheight = checkBalance(root->right);
    if(rightheight == -1) return -1;
    if(abs(leftheight - rightheight) > 1) return -1;
    return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}
bool isBalanced(struct TreeNode* root) {
    return checkBalance(root) != -1;
}

