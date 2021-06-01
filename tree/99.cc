/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        recur(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;            
        return;
    }
private:
    void recur(TreeNode* root) {
        if (!root)
            return;
        recur(root->left);
        // 相当于遍历升序数组
        if (!first && prev->val > root->val)
            first = prev;
        if (first && prev->val > root->val)
            second = root;
        prev = root;
        recur(root->right);        
    }
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;  
    TreeNode *prev = new TreeNode{INT_MIN};
};
