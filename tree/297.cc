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
        istringstream in(data);
        return mydeserialize(in);
    }
private:
    void myserialize(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "# ";
        } else {
            out << root->val << " ";
            myserialize(root->left, out);
            myserialize(root->right, out);
        }
    }
    
    TreeNode* mydeserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode{std::stoi(val)};
        root->left = mydeserialize(in);
        root->right = mydeserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
