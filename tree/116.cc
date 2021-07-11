/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

struct Item {
    Node* node;
    int level;
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        // level traversal
        std::queue<Item*> q_;
        Item *pre = nullptr;
        Item *i = new Item{root, 0};
        q_.emplace(i);
        while (!q_.empty()) {
            Item *cur = q_.front();
            q_.pop();
            if (cur->node->left) {
                Item *temp = new Item{cur->node->left, cur->level+1};
                q_.emplace(temp);
            }
            if (cur->node->right) {
                Item *temp = new Item{cur->node->right, cur->level+1};
                q_.emplace(temp);
            }
            if (!pre) {
                pre = cur;
                continue;
            }
            if (pre->level != cur->level) {
                pre = cur;
            } else {
                pre->node->next = cur->node;
                pre = cur;
            }
        }
        return root;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
struct Item {
    int level;
    Node* root;
};    
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        std::queue<Item*> q;
        Item *i = new Item{0, root};
        q.emplace(i);
        Node* pre = nullptr;
        int index = 0;
        while (!q.empty()) {
            Item *cur = q.front();
            q.pop();
            if (cur->level == index) {
                if (pre) {
                    pre->next = cur->root;
                    pre = pre->next;
                }
            } else {
                pre = cur->root;
                ++index;
            }
            if (cur->root->left) {
                Item *temp = new Item{cur->level+1, cur->root->left};
                q.emplace(temp);
            }
            if (cur->root->right) {
                Item *temp = new Item{cur->level+1, cur->root->right};
                q.emplace(temp);
            }
        }
        return root;        
    }
};
