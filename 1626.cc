class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        std::vector<std::pair<int, int>> pairs;
        int ret = 0;
        for (int i = 0; i < scores.size(); i++) {
            pairs.emplace_back(std::make_pair(ages[i], scores[i]));
        }
        std::sort(pairs.begin(), pairs.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });
        int dp[pairs.size()];
        for (int i = 0; i < pairs.size(); i++) {
            int score = pairs[i].second;
            dp[i] = score;
            for (int j = 0; j < i; j++) {
                if (pairs[j].second >= pairs[i].second) {
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};
