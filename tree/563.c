/**
 * heuristic and stupid recursion way
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum(struct TreeNode* root)
{
    if(root==NULL) return 0;
    return sum(root->left) + sum(root->right) + root->val;    
}

int findT(struct TreeNode* root)
{
    if(root==NULL) return 0;
    return abs(sum(root->left) - sum(root->right));
}
int findTilt(struct TreeNode* root) {
    if(root==NULL) return 0;
    return findT(root) + findTilt(root->left) + findTilt(root->right);
}
