class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        for (int i = 0; i < s.size(); i++) {
            next[i] = 0;
        }
        int j = 0;
        for (int i = 1; i < s.size();) {
            if (s[i] == s[j]) {
                next[i] = j+1;
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = next[j-1];
                } else {
                    next[i] = 0;
                    i++;
                }
            }
        }
        return next[s.size()-1] > 0 && s.size() % (s.size() - next[s.size()-1]) == 0;
    }
};
