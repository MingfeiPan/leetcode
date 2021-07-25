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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        root_ = root;
    }
    
    int next() {
        while (root_) {
            s_.emplace(root_);
            root_ = root_->left;
        }
        root_ = s_.top();
        s_.pop();
        int ret = root_->val;
        root_ = root_->right;
        return ret;
    }
    
    bool hasNext() {
        return root_ || !s_.empty();
    }
private:
    std::stack<TreeNode*> s_;
    TreeNode* root_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
