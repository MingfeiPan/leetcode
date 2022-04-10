class Solution {
public:
    int convertTime(string current, string correct) {
        int h = std::stoi(correct.substr(0, 2)) - std::stoi(current.substr(0, 2));
        int m = std::stoi(correct.substr(3, 2)) - std::stoi(current.substr(3, 2));
        int ret = 0;
        if (m < 0) {
            m += 60;
            --h;
        }
        while (m >= 15) {
            ret += m / 15;
            m = m % 15;
        }
        while (m >= 5) {
            ret += m / 5;
            m = m % 5;
        }
        return m + ret + h;
    }
};
