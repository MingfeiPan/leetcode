/**
 * 借助之前写的层次遍历, 返回每个子数组的最后一个, 很繁琐
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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    
    if(root==NULL) return NULL;
    int*** s = (int***)malloc(sizeof(int**));
    *s = NULL;
    int** columnSizes = (int**)malloc(sizeof(int*));
    *columnSizes = (int*)malloc(sizeof(int));
    *returnSize = 0;
    traverse(s, columnSizes, returnSize, root, 0);
    int* arr = (int*)malloc(sizeof(int)*(*returnSize + 1));
    for(int i = 0; i < *returnSize; i++)
    {
        arr[i] = (*s)[i][(*columnSizes)[i] - 1];
    }
    return arr;
}
void traverse(int*** s, int** columnSizes, int* returnSize, struct TreeNode* t, int depth);

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int*** s = (int***)malloc(sizeof(int**));
    *s = NULL;
    if(root==NULL) return *s;
    *returnSize = 0;
    traverse(s, columnSizes, returnSize, root, 0);
    return *s;
}

void traverse(int*** s, int**columnSizes, int* returnSize, struct TreeNode* t, int depth)
{
    if(t==NULL) return;
    if(*returnSize < depth + 1)
    {
        *returnSize = depth + 1;
        *s = (int**)realloc(*s, (depth+1)*sizeof(int*));
        (*s)[depth] = NULL;
        *columnSizes = (int*)realloc(*columnSizes, (depth+1)*sizeof(int));
        (*columnSizes)[depth] = 0;
    }
    (*s)[depth] = (int*)realloc((*s)[depth], ((*columnSizes)[depth]+1)*sizeof(int));
    (*s)[depth][(*columnSizes)[depth]] = t->val;
    ++(*columnSizes)[depth];
    traverse(s, columnSizes, returnSize, t->left, depth+1);
    traverse(s, columnSizes, returnSize, t->right, depth+1);
}
