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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = recur(nums, 0, nums.size()-1);
        return root;
    }
private:
    TreeNode* recur(std::vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int max = left;
        for (int index = left; index <= right; ++index) {
            if (nums[index] > nums[max]) {
                max = index;
            }
        }
        
        TreeNode* root = new TreeNode{nums[max]};
        root->left = recur(nums, left, max-1);
        root->right = recur(nums, max+1, right);
        return root;
    }
    
};
