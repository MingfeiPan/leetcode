class Solution {
public:
    int maxDepth(string s) {
        int ret = 0, cur = 0;
        for (char& c : s) {
            if (c == '(') {
                cur++;
                if (cur > ret) {
                    ret = cur;
                }
            }
            if (c == ')') {
                cur--;
            }
        }
        return ret;
    }
    
};
