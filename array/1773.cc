class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        std::unordered_map<std::string, int> m = {{"type",0}, {"color",1}, {"name",2}};
        auto iter = m.find(ruleKey);
        int index = iter->second;
        int ret = 0;
        for (const auto &item : items) {
            if (item[index] == ruleValue) {
                ++ret;
            }
        }
        return ret;
    }
};
