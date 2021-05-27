class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        int first = 0, second = 0;
        for (const auto &token : tokens) {
            if (token == "+") {
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                s.emplace(first + second);
            } else if (token == "-") {
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                s.emplace(second - first);                
            } else if (token == "*") {
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                s.emplace(first * second);                
            } else if (token == "/") {
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                s.emplace(second / first);                 
            } else {
                s.emplace(std::stoi(token));
            }
        }
        return s.top();
    }
};
