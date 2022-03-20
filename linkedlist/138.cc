/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        while (temp) {
            Node *node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        temp = head;
        while (temp) {
            temp->next->random = (temp->random) ? temp->random->next : nullptr;
            temp = temp->next->next;
        }
        Node* dummy = head->next;
        temp = head->next;
        while (head) {
            head->next = temp->next;
            head = head->next;
            if (!head) break;
            temp->next = head->next;
            temp = temp->next;
        }
        return dummy;
    }
};
