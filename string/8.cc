class Solution {
public:
    int myAtoi(string s) {
        int length = s.size(), index = 0;
        if (length == 0)
            return 0;
        while (index < length && s[index] == ' ')
            ++index;
        int sign = 1;
        if (s[index] == '-') {
            sign = -1;
            ++index;
        } else if (s[index] == '+') {
            ++index;
        }
        
        int64_t ret = 0;
        while (index < length) {
            if (isdigit(s[index])) {
                ret = ret*10 + (s[index] - '0');
                ++index;
                if (ret*sign > INT_MAX) {
                    return INT_MAX;
                }
                if (ret*sign < INT_MIN) {
                    return INT_MIN;
                }                
            } else {
                break;
            }
        }
        return ret*sign;
    }
};
