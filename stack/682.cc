class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::stack<int> s;
        for (const auto& c : ops) {
            if (c == "C") {
                if (!s.empty()) s.pop();
            } else if (c == "D") {
                if (!s.empty()) s.emplace(s.top()*2);
            } else if (c == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.emplace(a);
                s.emplace(a+b);
            } else {
                s.emplace(std::stoi(c));
            }
        }
        int ret = 0;
        while (!s.empty()) {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
};
