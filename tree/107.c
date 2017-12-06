/**
 * 在原有的层次遍历基础上, reverse结果数组就可以了
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void traverse(int*** s, int** columnSizes, int* returnSize, struct TreeNode* t, int depth);

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int*** s = (int***)malloc(sizeof(int**));
    *s = NULL;
    if(root==NULL) return *s;
    *returnSize = 0;
    traverse(s, columnSizes, returnSize, root, 0);
    int** ret = (int**)malloc((*returnSize)*sizeof(int*));
    int* retSize = (int*)malloc((*returnSize)*sizeof(int));
    int index;
    for(int i = 0; i<*returnSize;i++)
    {
        retSize[i] = (*columnSizes)[*returnSize-1-i];
        ret[i] = (int*)malloc(sizeof(int)*((*columnSizes)[*returnSize-1-i]+1));
        ret[i] = (*s)[*returnSize-1-i];
    }
    *columnSizes = retSize;
    //columnSizes = &retSize 是不对的,只改变了副本变量的地址 没有改变源地址
    return ret;
}

void traverse(int*** s, int**columnSizes, int* returnSize, struct TreeNode* t, int depth)
{
    if(t==NULL) return;
    if(*returnSize < depth + 1)
    {
        *returnSize = depth + 1;
        *s = (int**)realloc(*s, (depth+1)*sizeof(int*));
        (*s)[depth] = NULL;
        *columnSizes = (int*)realloc(*columnSizes, (depth+1)*sizeof(int*));
        (*columnSizes)[depth] = 0;
    }
    (*s)[depth] = (int*)realloc((*s)[depth], ((*columnSizes)[depth]+1)*sizeof(int));
    (*s)[depth][(*columnSizes)[depth]] = t->val;
    ++(*columnSizes)[depth];
    traverse(s, columnSizes, returnSize, t->left, depth+1);
    traverse(s, columnSizes, returnSize, t->right, depth+1);
}
