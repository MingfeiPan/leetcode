/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum;
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxPathDown(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = max(0, maxPathDown(root->left));
    int right = max(0, maxPathDown(root->right));
    sum = max(sum, left + right + root->val);
    return max(left, right) + root->val;
}

int maxPathSum(struct TreeNode* root) {
    sum = INT_MIN;
    if(root==NULL) return 0;
    maxPathDown(root);
    return sum;    
}



