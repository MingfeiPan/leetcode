class Solution {
public:
    string truncateSentence(string s, int k) {
        int space_count = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ')
                ++space_count;
            if (space_count == k) {
                return s.substr(0, i);
            }
        }
        return s;
    }
};
