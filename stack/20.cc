class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')') {
                if (stack.empty() || stack.pop() != '(') {
                    return false;
                }
            } else if (c == ']') {
                if (stack.empty() || stack.pop() != '[') {
                    return false;
                }
            } else if (c == '}') {
                if (stack.empty() || stack.pop() != '{') {
                    return false;
                }
            }
        }
        if (!stack.empty()) {
            return false;
        }
        return true;
    }
}


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (const auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.emplace(std::move(c));
            } else {
                if (st.empty()) return false;
                auto cur = st.top();
                if (c == ')' && cur != '(') return false;
                if (c == '}' && cur != '{') return false;
                if (c == ']' && cur != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
