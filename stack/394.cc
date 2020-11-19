class Solution {
public:
    string decodeString(string s) {
        std::stack<std::string> s_;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == ']') {
                std::string temp = "";
                while (s_.top() != "[") {
                    temp = s_.top() + temp;
                    s_.pop();
                }
                // find "["
                s_.pop();
                std::string repeat = "";
                while (!s_.empty() && s_.top() >= "0" && s_.top() <= "9") {
                    repeat = s_.top() + repeat;
                    s_.pop();
                }
                int repeat_num = std::stoi(repeat);
                repeat = "";
                while (repeat_num > 0) {
                    repeat += temp;
                    --repeat_num;
                }
                s_.emplace(repeat);
            } else {
                s_.emplace(string(1,s[index]));
            }
            ++index;
        }
        std::string ret = "";
        while (!s_.empty()) {
            ret = s_.top() + ret;
            s_.pop();
        }
        return ret;
    }
};
