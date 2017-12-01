/**
 * going recursive
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxd(struct TreeNode* root, int depth);

int maxDepth(struct TreeNode* root) {
    return maxd(root, 0);
}

int maxd(struct TreeNode* root, int depth)
{
    int depthleft, depthright;
    if(root==NULL) return depth;
    depthleft = maxd(root->left, depth+1);
    depthright = maxd(root->right, depth+1);
    return depthleft > depthright ? depthleft : depthright;
    
}
