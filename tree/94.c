/**
 * 中序遍历 用到stack 沿左链前进, 压栈到最左边的节点后一次出栈遍历
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


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode **s = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int length = 0;
    int i = 0;
    int *returnarray = (int*)malloc(sizeof(int));
    while(true)
    {
        while(root)
        {
            s = (struct TreeNode**)realloc(s, sizeof(struct TreeNode*)*(length + 1));
            s[length++] = root;
            root = root->left;
        }
        if(length == 0) break;
        root = s[--length];
        returnarray = (int*)realloc(returnarray, sizeof(int)*(i+1));
        returnarray[i++] = root->val;
        root = root->right;
    }
    *returnSize = i;
    return returnarray;
}
