/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (nullptr == node) return nullptr;
        return recur(node);
    }
private:
    std::unordered_map<int, Node*> visited_;
    Node* recur(Node* node) {
        if (nullptr == node) return nullptr;
        Node* new_node = new Node(node->val);
        visited_[new_node->val] = new_node;
        for (const auto& n : node->neighbors) {
            auto iter = visited_.find(n->val);
            if (iter != visited_.end()) {
                new_node->neighbors.emplace_back(iter->second);
            } else {
                Node* new_n = recur(n);
                new_node->neighbors.emplace_back(new_n);
            }
        }
        return new_node;
    }
};
