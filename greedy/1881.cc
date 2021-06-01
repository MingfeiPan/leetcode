class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] == '-') {
            for (int i = 1; i < n.size(); ++i) {
                int cur = (n[i] - '0');
                if (x < cur) {
                    return n.substr(0, i) + std::to_string(x) + n.substr(i);
                }
            }
        } else {
            for (int i = 0; i < n.size(); ++i) {
                int cur = (n[i] - '0');
                if (x > cur) {
                    return n.substr(0, i) + std::to_string(x) + n.substr(i);
                }
            }            
        }
        return n + std::to_string(x);
    }
};
