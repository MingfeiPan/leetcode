/**
 * simple and heuristic recursion solution
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL && q==NULL) return true;
    if(p==NULL) return false;
    if(q==NULL) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val);
}
