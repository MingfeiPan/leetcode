class Solution {
public:
    string removeKdigits(string num, int k) {
        std::stack<char> s;
        for (const auto& c : num) {
            while (!s.empty() && k > 0 && s.top() > c) {
                s.pop();
                --k;
            }
            if (!s.empty() || c != '0')
                s.emplace(c);
        }
        while (!s.empty() && k > 0) {
            s.pop();
            k--;
        }
        if (s.empty()) return "0";
        std::string ret = "";
        while (!s.empty()) {
            ret = s.top() + ret;
            s.pop();
        }
        return ret;
        return "0";
    }
};
