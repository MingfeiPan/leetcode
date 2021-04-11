class Solution {
struct Node {
    int val;
    Node *pre;
    Node *nxt;
};
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;
        Node *head = new Node{1};
        Node *cur, *dummy;
        dummy = head;
        int index = 2;
        while (n > 1) {
            cur = new Node{index};
            head->nxt = cur;
            cur->pre = head;
            head = cur;
            ++index;
            --n;
        }
        head = dummy;
        cur->nxt = head;
        head->pre = cur;
        Node *pre, *nxt;
        cur = head;
        while (cur != cur->nxt) {
            index = 1;
            while (index < k) {
                cur = cur->nxt;
                ++index;
            }
            if (cur->nxt == cur)
                return cur->val;
            pre = cur->pre;
            nxt = cur->nxt;
            pre->nxt = nxt;
            nxt->pre = pre;
            cur = nxt;
        }
        return cur->val;
    }
};
