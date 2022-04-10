class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::unordered_map<int, int> losts;
        for (const auto& match : matches) {
            ++losts[match[1]];
        }
        std::vector<std::vector<int>> ret;
        std::unordered_set<int> r1;
        std::unordered_set<int> r2;
        for (const auto& match : matches) {
            auto iter = losts.find(match[0]);
            if (iter == losts.end()) r1.emplace(match[0]);
            auto iter_win = losts.find(match[1]);
            if (iter_win != losts.end() && iter_win->second == 1) r2.emplace(match[1]);
        }
        std::vector<int> v1(r1.begin(), r1.end());
        std::sort(v1.begin(), v1.end());
        ret.emplace_back(std::move(v1));
        std::vector<int> v2(r2.begin(), r2.end());
        std::sort(v2.begin(), v2.end());
        ret.emplace_back(std::move(v2));
        return ret;
    }
};
