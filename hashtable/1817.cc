class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        std::unordered_map<int, std::unordered_set<int>> check;
        for (const auto & log : logs) {
            auto check_iter = check.find(log[0]);
            if (check_iter == check.end()) {
                std::unordered_set<int> temp = {log[1]};
                check.emplace(log[0], temp);
            } else {
                check_iter->second.emplace(log[1]);
            }
        }
        std::vector<int> ret(k, 0);
        for (auto iter = check.begin(); iter != check.end(); ++iter) {
            ++ret[iter->second.size()-1];
        }
        return ret;
    }
};
