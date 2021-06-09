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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, index, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(std::vector<int>& preorder, int& preindex, std::vector<int>& inorder, int instart, int inend) {
        if (preindex == preorder.size() || instart > inend)
            return nullptr;
        int index = instart;
        while (index <= inend) {
            if (inorder[index] == preorder[preindex]) {
                break;
            }
            ++index;
        }
        TreeNode* root = new TreeNode{preorder[preindex]};
        ++preindex;
        root->left = build(preorder, preindex, inorder, instart, index-1);
        root->right = build(preorder, preindex, inorder, index+1, inend);
        return root;
    }
};
