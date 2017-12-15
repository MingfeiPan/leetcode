/**
 * post order iteration traversal is quite hard, try recursion first...
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
void postO(struct TreeNode* root, int* returnSize, int** returnArr)
{
    if(root==NULL) return;
    postO(root->left, returnSize, returnArr);
    postO(root->right, returnSize, returnArr);
    *returnArr = realloc(*returnArr, sizeof(int)*((*returnSize)+1));
    (*returnArr)[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int** returnArr = (int**)malloc(sizeof(int*));
    *returnArr = (int*)malloc(sizeof(int)); //注意要给数组的第一个值分配地址 才能realloc
    *returnSize = 0;
    postO(root, returnSize, returnArr);
    return *returnArr;
}
