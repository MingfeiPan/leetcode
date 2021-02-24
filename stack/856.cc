class Solution {
public:
    int scoreOfParentheses(string S) {
        std::stack<int> s;
        s.push(0);
        for (const auto &c : S) {
            if (c == '(') {
                s.push(0);
            } else {
                int cur = s.top();
                s.pop();
                int pre = s.top();
                s.pop();
                s.push(pre + std::max(2*cur, 1));
            }
        }
        return s.top();
    }
};
