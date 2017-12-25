/**
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
void findM(struct TreeNode* root, int **ret, int* returnSize, int* maxCount, int* count, int *num)
{
    if(root==NULL) return;
    findM(root->left, ret, returnSize, maxCount, count, num);
    if(*num == INT_MIN) *num = root->val;
    if(root->val == *num)
    {
        (*count)++;
    }
    else
    {
        if(*count > *maxCount)
        {
            (*ret)[0] = *num;
            *returnSize = 1;
            *maxCount = *count;
        }
        else if(*count==*maxCount)
        {
            *ret = (int*)realloc(*ret, sizeof(int)*(*returnSize+1));
            (*ret)[*returnSize] = *num;
            (*returnSize)++;
        }
        *count = 1;
        *num = root->val;
    }
    findM(root->right, ret, returnSize, maxCount, count, num);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    if(root == NULL) return NULL;
    int* ret = (int*)malloc(sizeof(int));
    int maxCount = 0;
    int count = 0;
    int num = INT_MIN;
    findM(root, &ret, returnSize, &maxCount, &count, &num);
    if(maxCount==count)
    {
        ret = (int*)realloc(ret, sizeof(int)*(*returnSize+1));
        ret[*returnSize] = num;
        (*returnSize)++;
    }
    else if(maxCount < count)
    {
        ret[0] = num;
        *returnSize = 1;
    }
    return ret;
}
