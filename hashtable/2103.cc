class Solution {
public:
    int countPoints(string rings) {
        std::vector<std::unordered_map<char, int>> counter;
        for (int i = 0; i < 10; ++i) {
            std::unordered_map<char, int> m;
            counter.emplace_back(std::move(m));
        }
        for (int i = 0; i < rings.size(); i+=2) {
            counter[rings[i+1]-'0'][rings[i]] = 1;
        }
        int ret = 0;
        for (const auto& c : counter) {
            if (c.size() == 3) {
                ++ret;
            }
        }
        return ret;
    }
};
