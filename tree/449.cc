/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string str = "";
        if (!root)
            return str;
        std::stack<TreeNode*> s_;
        s_.push(root);
        while (!s_.empty()) {
            root = s_.top();
            s_.pop();
            str += std::to_string(root->val);
            str += ".";
            if (root->right) {
                s_.push(root->right);
            }
            if (root->left) {
                s_.push(root->left);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::queue<int> q_;
        std::string temp = "";
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '.') {
                q_.push(std::stoi(temp));
                temp = "";
            } else {
                temp += data[i];
            }
        }
        
        return recur(q_, INT_MIN, INT_MAX);
    }
private:
    TreeNode* recur(std::queue<int>& q_, int lower, int upper) {
        if (q_.empty())
            return nullptr;
        int val = q_.front();
        if (val < lower || val > upper)
            return nullptr;
        q_.pop();
        TreeNode* root = new TreeNode{val};
        root->left = recur(q_, lower, val);
        root->right = recur(q_, val, upper);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        myserialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        istringstream in(data);
        std::string val;
        in >> val;
        TreeNode* root = new TreeNode{std::stoi(val)};
        while (in >> val) {
            buildTree(root, std::stoi(val));
        }
        return root;
    }
private:
    void myserialize(TreeNode* root, ostringstream& out) {
        if (!root)
            return;
        out << root->val << " ";
        myserialize(root->left, out);
        myserialize(root->right, out);
    }
    
    void buildTree(TreeNode* root, int val) {
        if (root->val < val) {
            if (!root->right) {
                root->right = new TreeNode{val};
            } else {
                buildTree(root->right, val);
            }
        } else {
            if (!root->left) {
                root->left = new TreeNode{val};
            } else {
                buildTree(root->left, val);
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
