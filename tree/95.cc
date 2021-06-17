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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return std::vector<TreeNode*>();
        return recur(1, n);
    }
private:
    std::vector<TreeNode*> recur(int low, int high) {
        if (low > high) {
            return std::vector<TreeNode*>{nullptr};
        }
        std::vector<TreeNode*> ret, left, right;
        for (int i = low; i <= high; ++i) {
            left = recur(low, i-1);
            right = recur(i+1, high);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode *root = new TreeNode{i};
                    root->left = l;
                    root->right = r;
                    ret.emplace_back(root);
                }
            }
        }
        return ret;
    }
};;
