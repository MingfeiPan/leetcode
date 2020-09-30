class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size()+1];
        for (int i = 0; i <= s.size(); i++) {
            dp[i] = false;
        }
        std::unordered_set st(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] && st.find(s.substr(j, i-j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
