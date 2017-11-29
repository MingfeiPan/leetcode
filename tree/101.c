/**
 * still recursive
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSame(struct TreeNode*, struct TreeNode*);
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL) return true;
    return isSame(root->left, root->right);
}

bool isSame(struct TreeNode* left, struct TreeNode* right)
{
    if(left==NULL&&right==NULL) return true;
    if(left!=NULL&&right==NULL) return false;
    if(left==NULL&&right!=NULL) return false;
    return isSame(left->left, right->right) && isSame(left->right, right->left) && left->val==right->val;
}
