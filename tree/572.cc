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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (issame(root, subRoot))
            return true;
        else {
            if (root)
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);   
        }
        return false;
    }
private:
    bool issame(TreeNode* source, TreeNode* target) {
        if (!source && !target)
            return true;
        if (!source || !target)
            return false;
        return source->val == target->val && issame(source->left, target->left) && issame(source->right, target->right);
    }
};
