class Solution {
public:
    string toLowerCase(string s) {
        for (auto &c : s) {
            if (c <= 90 && c >= 65)
                c += 32;
        }
        return s;
    }
};
