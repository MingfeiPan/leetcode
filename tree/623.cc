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
    int level;
    TreeNode* root;
};
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newroot = new TreeNode(val);
            if (root) {
                newroot->left = root;
            }
            return newroot;
        } 
        if (!root) {
            return root;
        }    
        std::queue<Item> q;
        q.push(Item{1, root});
        while (!q.empty()) {
            Item cur = q.front();
            q.pop();
            if ((cur.level+1) < depth) {
                if (cur.root->left) {
                    q.push(Item{cur.level+1, cur.root->left});
                }    
                if (cur.root->right) {
                    q.push(Item{cur.level+1, cur.root->right});
                }
            } else if ((cur.level+1) == depth) {
                // found
                TreeNode *newleft = new TreeNode{val};
                TreeNode *newright = new TreeNode{val};
                newleft->left = cur.root->left;
                newright->right = cur.root->right;                
                cur.root->left = newleft;
                cur.root->right = newright;
            } else {
                break;
            }
        }
        return root;
    }
};

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newroot = new TreeNode{val};
            newroot->left = root;
            return newroot;
        }
        recur(root, 2, val, depth);
        return root;
    }
private:
    void recur(TreeNode* root, int level, int& val, int& depth) {
        if (!root)
            return;
        if (level == depth) {
            TreeNode* newleft = new TreeNode{val};
            TreeNode* newright = new TreeNode{val};
            if (root->left) {
                auto left = root->left;
                root->left = newleft;
                newleft->left = left;
            } else {
                root->left = newleft;
            }
            if (root->right) {
                auto right = root->right;
                root->right = newright;
                newright->right = right;
            } else {
                root->right = newright;
            }
            return;
        }
        if (level < depth) {
            recur(root->left, level+1, val, depth);
            recur(root->right, level+1, val, depth);
        }
        return;
    }
};
