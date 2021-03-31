class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        std::sort(envelopes.begin(), envelopes.end(), [&](std::vector<int> &a, std::vector<int> &b){
            return a[0] < b[0];
        });
        std::vector<int> dp(envelopes.size(), 1);
        for (size_t i = 1; i < envelopes.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if ((envelopes[i][0] > envelopes[j][0]) && (envelopes[i][1] > envelopes[j][1])) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
        }
        int ret = 0;
        for (const auto &i : dp) {
            ret = std::max(ret, i);
        }
        return ret;
    }
};
