/**
 * simple recursive
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(numsSize == 0) return NULL;
    int i = (numsSize % 2) ? (numsSize / 2) : (numsSize / 2 - 1);
    int rootval = nums[i];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootval;
    root->left = sortedArrayToBST(nums, i);
    root->right = sortedArrayToBST(nums+i+1, numsSize-i-1);
    return root;
}
