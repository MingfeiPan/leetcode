class Solution {
public:
    int titleToNumber(string columnTitle) {
        int64_t ret = 0;
        for (const auto& c : columnTitle) {
            ret = 26*ret + c -'A' + 1;
        }
        return ret;
    }
};
