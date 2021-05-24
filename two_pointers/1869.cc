class Solution {
public:
    bool checkZeroOnes(string s) {
        if (s.size() == 1) {
            if (s[0] == '1')
                return true;
            return false;
        }
        int ones = 0, zeros = 0, index = 1, cur = 1;
        while (index < s.size()) {
            if (s[index] == s[index-1]) {
                ++cur;
            } else {
                if (s[index] == '0') {
                    ones = std::max(ones, cur);
                } else {
                    zeros = std::max(zeros, cur);
                }
                cur = 1;
            }
            ++index;
        }
        if (s[index-1] == '1') {
            ones = std::max(ones, cur);
        } else {
            zeros = std::max(zeros, cur);
        }

        return ones > zeros;
    }
};
