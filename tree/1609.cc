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
struct Item {
    TreeNode* node;
    int level;
};
public:
    bool isEvenOddTree(TreeNode* root) {
        // use a vector for each level node
        std::vector<int> last_;
        std::queue<Item> q_;
        q_.emplace(Item{root, 0});
        while (!q_.empty()) {
            Item i = q_.front();
            q_.pop();
            if (last_.size() <= i.level) {
                if (i.level % 2 == 0) {
                    if (i.node->val % 2 == 0)
                        return false;                    
                } else {
                    if (i.node->val % 2 != 0)
                        return false;                    
                }
                last_.emplace_back(i.node->val);
            } else {
                // check odd even
                if (i.level % 2 == 0) {
                    if (i.node->val % 2 == 0)
                        return false;
                    if (i.node->val <= last_[i.level]) {
                        return false;
                    } else {
                        last_[i.level] = i.node->val;
                    }
                } else {
                    if (i.node->val % 2 != 0)
                        return false;
                    if (i.node->val >= last_[i.level]) {
                        return false;
                    } else {
                        last_[i.level] = i.node->val;
                    }
                }
            }
            if (i.node->left) {
                q_.emplace(Item{i.node->left, i.level+1});
            }
            if (i.node->right) {
                q_.emplace(Item{i.node->right, i.level+1});
            }
        }
        return true;
    }
};
