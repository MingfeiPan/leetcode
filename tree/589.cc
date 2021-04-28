/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        std::vector<int> ret;
        if (!root)
            return ret;
        std::stack<Node*> s;
        s.emplace(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            ret.emplace_back(root->val);
            for (int i = root->children.size()-1; i >= 0; --i) {
                s.emplace(root->children[i]);
            }
        }
        return ret;
    }
};
