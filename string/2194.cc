class Solution {
public:
    vector<string> cellsInRange(string s) {
        std::vector<std::string> ret;
        auto r1 = s[0] - 'A';
        auto c1 = s[1] - '0';
        auto r2 = s[3] - 'A';
        auto c2 = s[4] - '0';
        std::string t1, t2;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                t1 = i + 'A';
                t2 = j + '0';
                ret.emplace_back(t1+t2);
            }
        }
        return ret;
    }
};
