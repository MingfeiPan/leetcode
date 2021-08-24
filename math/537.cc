class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        std::string real1 = "", com1 = "", real2 = "", com2 = "";
        split(&real1, &com1, num1);
        split(&real2, &com2, num2);
        int r1r2 = std::stoi(real1) * std::stoi(real2);
        int c1c2 = std::stoi(com1) * std::stoi(com2);
        int compart = std::stoi(real1) * std::stoi(com2) + std::stoi(real2) * std::stoi(com1);
        std::string ret = std::to_string(r1r2 - c1c2) + "+" + std::to_string(compart) + "i";
        return ret;
    }
private:
    void split(std::string* real, std::string* com, std::string& pattern) {
        for (int i = 0; i < pattern.size(); ++i) {
            if (pattern[i] == '+') {
                *real = pattern.substr(0, i);
                *com = pattern.substr(i+1, pattern.size()-i-2);
                return;
            }
        }
    }
};
