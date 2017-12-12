/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {

    while(root)
    {
        struct TreeLinkNode* pre = (struct TreeLinkNode*)malloc(sizeof(struct TreeLinkNode));
        pre->val = 0;
        pre->next = NULL;
        pre->left = NULL;
        pre->right = NULL;
        struct TreeLinkNode* cur = pre;;        
        while(root)
        {
            if(root->left)
            {
                cur->next = root->left;
                cur = cur->next;
            }
            if(root->right)
            {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
        }
        root = pre->next;
    }    
}
