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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> ret;
        if (!root1 && !root2) {
            return ret;
        }
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;
        while (true) {
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }
            if (s1.empty() || s2.empty()) {
                break;
            }
            root1 = s1.top();
            root2 = s2.top();
            if (root1->val < root2->val) {
                ret.emplace_back(root1->val);
                s1.pop();
                root1 = root1->right;
                root2 = nullptr;
            } else {
                ret.emplace_back(root2->val);
                s2.pop();
                root1 = nullptr;
                root2 = root2->right;
            }
        }
        if (!s1.empty()) {
            single(s1, ret);   
        } else {
            single(s2, ret);
        }
        return ret;
    }
    
    void single(std::stack<TreeNode*> s, std::vector<int>& ret) {
        TreeNode* root = nullptr;
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (s.empty()) {
                break;
            }
            root = s.top();
            s.pop();
            ret.emplace_back(root->val);
            root = root->right;
        }
        return;
    }
};
