class Solution {
public:
    int minSteps(string s, string t) {
        std::vector<int> m1(26, 0), m2(26, 0);
        for (const auto& c : s)
            ++m1[c-'a'];
        for (const auto& c : t)
            ++m2[c-'a'];
        int ret = 0;
        for (int i = 0; i < 26; ++ i) {
            if (m1[i] < m2[i]) {
                ret += m2[i] - m1[i];
            } else {
                ret += m1[i] - m2[i];
            }
        }
        return ret;
    }
};
