/**
 * 借助层次遍历, 注意stack的结构很简陋 需要两个flag来标识位置
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* Tree;
    
int findBottomLeftValue(struct TreeNode* root) {
    Tree *s = (Tree*)malloc(sizeof(Tree));
    int length = 0;
    int i = 0;
    int result;
    int j;
    s[length++] = root;
    while(length > i)
    {   
        int size = length - i;
        for(j = 0; j < size; j++)
        {
            root = s[i+j];
            if(j == 0) result = root->val;
            if(root->left)
            {   
                s = (Tree*)realloc(s, sizeof(Tree)*(length + 1));
                s[length++] = root->left;
            }   
            if(root->right)
            {   
                s = (Tree*)realloc(s, sizeof(Tree)*(length + 1));
                s[length++] = root->right;
            }  
        }
        i = i + size;
    } 
    return result;
}
