/**
 * 借助中序遍历
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {
    if(root==NULL) return 0;
    struct TreeNode** s = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    //int* l = (int*)malloc(sizeof(int));
    int length = 0;
    //int size = 0;
    while(true)
    {
        while(root)
        {
            s = (struct TreeNode**)realloc(s, sizeof(struct TreeNode*)*(length+1));
            s[length++] = root;
            root = root->left;
        }
        root = s[--length];
        if(k-- == 1) return root->val;
        root = root->right;
    }
}
