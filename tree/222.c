/**
 * 对于每个节点, 一路向左求出lf,一路向右求出lr, 如果lf==lr 则一定是满二叉树 可以2^n - 1 得出节点数, 否则继续递归
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(root == NULL) return 0;
    struct TreeNode* left = root;
    struct TreeNode* right= root;
    int hl = 0;
    int hr = 0;
    while(left) 
    {
        hl++;
        left = left->left;
    }
    while(right)
    {
        hr++;
        right = right->right;
    }
    if(hl == hr) return pow(2, hl) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
