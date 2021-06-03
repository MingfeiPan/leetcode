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
    TreeNode* root;
    int level;
};
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if (!root)
            return ret;
        std::queue<Item> q;
        q.emplace(Item{root, 0});
        int index = 0;
        std::vector<int> cur;
        while (!q.empty()) {
            Item item = q.front();
            q.pop();
            if (item.level != index) {
                if (index % 2 == 1)
                    reverse(cur);                
                ++index;
                std::vector<int> temp;
                cur.swap(temp);
                ret.emplace_back(std::move(temp));
            }
            cur.emplace_back(item.root->val);
            if (item.root->left) {
                q.emplace(Item{item.root->left, item.level+1});
            }
            if (item.root->right) {
                q.emplace(Item{item.root->right, item.level+1});
            }
        }
        if (index % 2 == 1)
            reverse(cur);
        ret.emplace_back(std::move(cur));
        return ret;        
    }
private:
    void reverse(std::vector<int>& nums) {
        for (int i = 0, j = nums.size()-1; i < j; ++i, --j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return;
    }
};
