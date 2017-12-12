/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL) return;
    struct TreeLinkNode* pre = root;
    struct TreeLinkNode* cur;
    while(pre->left)
    {
        cur = pre;
        while(cur)
        {
            cur->left->next = cur->right;
            if(cur->next)
            {
                cur->right->next = cur->next->left; //链接上层相邻node的right->left
            }
            cur = cur->next; //通过cur的横向移动 会把下层的相关node链接起来
        }
        pre = pre->left;
    }
}
