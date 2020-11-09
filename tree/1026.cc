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
    int maxAncestorDiff(TreeNode* root) {
        int ret = 0;
        recur(root->left, ret, root->val, root->val);
        recur(root->right, ret, root->val, root->val);
        return ret;
    }
private:
    void recur(TreeNode* root, int& ret, int maxancestor, int minancestor) {
        if (!root)
            return;
        int cur = abs(root->val - maxancestor);
        if (cur > ret) {
            ret = cur;
        }
        cur = abs(root->val - minancestor);
        if (cur > ret) {
            ret = cur;
        }        
        if (root->val > maxancestor) {
            maxancestor = root->val;
        }
        if (root->val < minancestor) {
            minancestor = root->val;
        }        
        recur(root->left, ret, maxancestor, minancestor);
        recur(root->right, ret, maxancestor, minancestor);
    }
};
