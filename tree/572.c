/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isS(struct TreeNode* s, struct TreeNode* t)
{
    if(s==NULL && t==NULL) return true;
    if((s==NULL && t!=NULL) || (s!=NULL && t==NULL)) return false;
    if(s->val != t->val) return false;
    return isS(s->left, t->left) && isS(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if(s==NULL) return false;
    if(isS(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
