class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i1 = 0, i2 = 0;
        while (i1 < s.size() && i2 < t.size()) {
            while (i2 < t.size() && s[i1] != t[i2])
                ++i2;
            if (i2 == t.size() && i1 != s.size()) return false;
            ++i1;
            ++i2;
        }
        if (i1 == s.size()) return true;
        return false;
    }
};
