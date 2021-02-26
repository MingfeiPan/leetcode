class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> s;
        int index = 0;
        for (const auto &i : pushed) {
            s.push(i);
            while (!s.empty() && index < popped.size() && s.top() == popped[index]) {
                s.pop();
                ++index;
            }
        }
        return index == popped.size();
    }
};
