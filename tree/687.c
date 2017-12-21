/**
 * 递归每一个node, 同时每一个node也要递归子节点
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max2(int a, int b)
{
    return a < b ? b : a;
}

int max3(int a, int b, int c)
{
    int temp;
    temp = a < b ? b : a;
    return temp < c ? c : temp;
}

int longestU(struct TreeNode* root, int i)
{
    if(root == NULL || root->val != i) return 0;
    return max2(longestU(root->left, i), longestU(root->right, i)) + 1;
}
int longestUnivaluePath(struct TreeNode* root) {
    if(root==NULL) return 0;
    return max3(longestUnivaluePath(root->left), longestUnivaluePath(root->right), (longestU(root->left, root->val) + longestU(root->right, root->val)));
}
