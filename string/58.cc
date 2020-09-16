class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        bool flag = false;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] != ' ') {
                flag = true;
                ret++;
            } else {
                if (!flag) {
                    continue;
                } else {
                    break;   
                }
            }
        }
        return ret;
    }
};
