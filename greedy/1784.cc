class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        bool cont_flag = false;
        for (const auto &c : s) {
            if (c == '1') {
                if (flag && !cont_flag) {
                    return false;
                }
                flag = true;
                cont_flag = true;
            } else {
                cont_flag = false;
            }
        }
        return true;
    }
};
