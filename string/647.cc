class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        for (int index = 0; index < s.size(); ++index) {
            for (int i = index, j = index+1; i >= 0 && j < s.size(); --i, ++j) {
                if (s[i] == s[j]) {
                    ++ret;
                } else {
                    break;
                }
            }
            ++ret;
            for (int i = index-1, j = index+1; i >= 0 && j < s.size(); --i, ++j) {
                if (s[i] == s[j]) {
                    ++ret;
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};
