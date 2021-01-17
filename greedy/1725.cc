class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        std::unordered_map<int, int> counter;
        int max = 0;
        for (auto& rec : rectangles) {
            int len = std::min(rec[0], rec[1]);
            auto iter = counter.find(len);
            if (iter == counter.end()) {
                counter.emplace(len, 1);
            } else {
                ++iter->second;
            }
            max = std::max(max, len);
        }
        auto ret = counter.find(max);
        return ret->second;
    }
};
