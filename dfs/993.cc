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
    bool isCousins(TreeNode* root, int x, int y) {
        int depth_x = 0, depth_y = 0, father_x = -1, father_y = -1;
        recur(root, x, depth_x, father_x, 0);
        recur(root, y, depth_y, father_y, 0);
        if (father_x == -1 || father_y == -1)
            return false;
        return father_x != father_y && depth_x == depth_y;
    }
private:
    void recur(TreeNode* root, int target, int& depth, int& father, int cur) {
        if (!root)
            return;
        if (root->left && root->left->val == target) {
            depth = cur;
            father = root->val;
            return;
        } 
        if (root->right && root->right->val == target) {
            depth = cur;
            father = root->val;
            return;
        }
        recur(root->left, target, depth, father, cur+1);
        recur(root->right, target, depth, father, cur+1);
        return;
    }
};
