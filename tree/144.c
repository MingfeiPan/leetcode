/**
 * using a simple stack
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode** s = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    struct TreeNode* p;
    int length = 0;
    int* arr = (int*)malloc(sizeof(int));
    *returnSize = 0;
    if(root)
    {
        s = (struct TreeNode**)realloc(s, sizeof(struct TreeNode*)*(length+1));
        s[length++] = root;
    }
    while(length > 0)
    {
        p = s[--length];
        arr = (int*)realloc(arr, sizeof(int)*((*returnSize)+1));
        arr[(*returnSize)++] = p->val;
        
        if(p->right)
        {
            s = (struct TreeNode**)realloc(s, sizeof(struct TreeNode*)*(length+1));
            s[length++] = p->right;
        }
        if(p->left)
        {
            s = (struct TreeNode**)realloc(s, sizeof(struct TreeNode*)*(length+1));
            s[length++] = p->left;
        }        
    }
    return arr;
}
