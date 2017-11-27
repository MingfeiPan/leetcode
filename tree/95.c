/**
 * 递归方法, 并没有走dp
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

struct TreeNode* push(struct TreeNode ***arr, int* returnSize, int a)
{
    struct TreeNode* t = NULL;
    if(a > 0)
    {
        t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        t->val = a;
        t->left = NULL;
        t->right = NULL;
    }
    *returnSize += 1;
    *arr = (struct TreeNode**)realloc(*arr, sizeof(struct Treenode*) * (*returnSize));
    (*arr)[*returnSize-1] = t;
    return t;
}

struct TreeNode** gen(int start, int end, int* returnSize)
{
    struct TreeNode** arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    if(start > end)
    {
        push(&arr, returnSize, 0);
        return arr;
    }
    
    for(int i = start; i <= end; i++)
    {
        int count1 = 0;
        int count2 = 0;
        struct TreeNode **arr1 = gen(start, i-1, &count1);
        struct TreeNode **arr2 = gen(i+1, end, &count2);
        for(int m=0; m<count1;m++)
        {
            for(int n=0; n<count2;n++)
            {
                struct TreeNode* t = push(&arr, returnSize, i);
                t->left = arr1[m];
                t->right = arr2[n];
            }
        }
        
    }
    return arr;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    *returnSize = 0;
    if(!n) return NULL;
    return gen(1,n,returnSize);
}
