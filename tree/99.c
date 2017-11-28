/**
 * 在中序遍历中寻找两个错误的node  前一个大于后一个的时候 可以在前一个找到较大的那个错误node  在后一个找到较小的那个错误node
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    if(!root) return;
    struct TreeNode** s = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    struct TreeNode* t1;
    struct TreeNode* t2;
    int len = 0;
    int temp;
    struct TreeNode* prev;
    while(true)
    {
        while(root)
        {
            s = (struct TreeNode**)realloc(s, sizeof(struct TreeNode*)*(len+1));
            s[len++] = root;
            root = root->left;
        }
        if(len == 0) break;
        root = s[--len];
        
        if(prev != NULL)
        {
            printf("%d\n",prev->val);
            if(prev->val >= root->val)
            {
                if(t1 == NULL) t1 = prev;
                t2 = root;
            }
        }    
        prev = root;
        root = root->right;
    }
    temp = t1->val;
    t1->val = t2->val;
    t2->val = temp;
    return;
}
