class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::stack<int> st;
        std::unordered_set<int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.emplace(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    m.emplace(i);
                }
            }
        }
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            m.emplace(cur);
        }
        std::string ret;
        for (int i = 0; i < s.size(); ++i) {
            if (!m.count(i))
                ret += s[i];
        }
        return ret;
    }
};
