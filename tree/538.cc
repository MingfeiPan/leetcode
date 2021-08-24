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
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        std::vector<int> nums;
        inOrder(root, &nums);
        
        TreeNode* dummy = root;
        std::stack<TreeNode*> s;
        int index = 0;
        int sum = getsum(nums);
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            sum -= nums[index];
            ++index;
            root->val += sum;
            root = root->right;            
        }
        return dummy;
    }
private:
    int getsum(std::vector<int>& nums) {
        int sum = 0;
        for (const auto &num : nums) {
            sum += num;
        }
        return sum;
    }
    void inOrder(TreeNode *root, std::vector<int> *nums) {
        if (!root)
            return;
        std::stack<TreeNode*> s;
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            nums->push_back(root->val);
            root = root->right;
        }
        return;
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        TreeNode *dummy = root;
        std::stack<TreeNode*> s;
        int sum = 0;
        while (true) {
            while (root) {
                s.push(root);
                root = root->right;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            int temp = sum;
            sum += root->val;
            root->val += temp;
            root = root->left;
        }
        return dummy;
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        TreeNode *dummy = root;
        std::stack<TreeNode*> s;
        int sum = 0;
        while (true) {
            while (root) {
                s.push(root);
                root = root->right;
            }
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            int temp = sum;
            sum += root->val;
            root->val += temp;
            root = root->left;
        }
        return dummy;
    }
};
