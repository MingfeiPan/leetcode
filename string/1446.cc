class Solution {
public:
    int maxPower(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int ret = 1, cur = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i-1] == s[i]) {
                ++cur;
            } else {
                if (cur > ret)
                    ret = cur;
                cur = 1;
            }
        }
        if (cur > ret)
            ret = cur;        
        return ret;
    }
};
