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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        return recur(inorder, 0, inorder.size()-1, postorder, index);
    }

private:
    TreeNode* recur(std::vector<int>& inorder, int start, int end, std::vector<int>& postorder, int& postindex) {
        if (postindex < 0 || start > end) {
            return nullptr;
        }
        int index = start;
        while (index <= end) {
            if (inorder[index] == postorder[postindex]) {
                break;
            }
            ++index;
        }
        TreeNode *root = new TreeNode{postorder[postindex]};
        --postindex;
        root->right = recur(inorder, index+1, end, postorder, postindex);
        root->left = recur(inorder, start, index-1, postorder, postindex);
        return root;
    }
};
