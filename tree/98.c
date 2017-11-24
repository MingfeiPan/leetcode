/**
 * 中序遍历之后, 通过检查数列是否有逆序对 来判断true false, 应该有更直接的 不用转一步数组
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST(struct TreeNode* root) {
    struct TreeNode **s = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
    int *arr;
    int length = 0;
    int len = 0;
    int temp;
    while(true)
    {
        while(root)
        {
            s = (struct TreeNode **)realloc(s, sizeof(struct Treenode*)*(length+1));
            s[length++] = root;
            root = root->left;
        }
        if(length == 0) break;
        root = s[--length];
        arr = (int*)realloc(arr, sizeof(int) * (len + 1));
        arr[len++] = root->val;
        root = root->right;
    }
    for(int i=0; i< len-1;i++){
        if(arr[i] >= arr[i+1]) return false;
    }
    return true;
}

