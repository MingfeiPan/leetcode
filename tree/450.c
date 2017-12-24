/**
 * 删除时 需考虑单分支 双分支情况
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root==NULL) return NULL;
    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    dummy->val = 0;
    dummy->left = NULL;
    dummy->right = root;
    struct TreeNode* head = dummy;
    
    while(root != NULL && root->val != key)
    {
        dummy = root;
        if(root-> val < key) root = root->right;
        else root = root->left;
    }
    
    if(root != NULL && root->left != NULL)
    {
        struct TreeNode* del = root->left;
        dummy = root;
        while(del->right != NULL)
        {
            dummy = del;
            del = del->right;
        }
        root->val = del->val;
        root = del;
    }
    
    struct TreeNode* next = root;
    if(next != NULL && next->left != NULL) next = next->left;
    else if(next != NULL) next = next->right;
    
    if(dummy->left == root) dummy->left = next;
    else dummy->right = next;
    
    return head->right;
    
    
}
