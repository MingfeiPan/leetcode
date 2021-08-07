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
struct Item {
    Node* root;
    int level;
};
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> ret;
        if (!root)
            return ret;
        std::queue<Item> q;
        q.emplace(Item{root, 0});
        int index = 0;
        std::vector<int> cur;
        while (!q.empty()) {
            Item i = q.front();
            q.pop();
            if (index != i.level) {
                std::vector<int> temp;
                temp.swap(cur);
                ret.emplace_back(temp);
                ++index;
            }
            cur.emplace_back(i.root->val);
            for (const auto& node : i.root->children) {
                q.emplace(Item{node, i.level+1});
            }
        }
        ret.emplace_back(cur);
        return ret;
    }
};
