/**
 * keey recursive
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* myfunction(int* nums, int start, int end);

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if(numsSize==0) return NULL; 
    return aa(nums, 0, numsSize-1);    
}

struct TreeNode* myfunction(int* nums, int start, int end)
{
    if(end < start) return NULL;
    int temp = INT_MIN;
    int i;
    for(i = start; i <= end; i++)
    {
        if(temp < nums[i]) temp = nums[i];
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = temp;
    root->left = myfunction(nums, start, i-1);
    root->right = myfunction(nums, i+1, end);
    return root;    
}
