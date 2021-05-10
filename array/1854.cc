class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        std::unordered_map<int, int> m;
        for (const auto &log : logs) {
            for (int i = log[0]; i < log[1]; ++i) {
                auto iter = m.find(i);
                if (iter == m.end()) {
                    m[i] = 1;
                } else {
                    ++m[i];
                }
            }
        }
        int retyear = 0, retcount = 0;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second > retcount) {
                retcount = iter->second;
                retyear = iter->first;
            } else if (iter->second == retcount) {
                retyear = std::min(retyear, iter->first);
            }
        }
        return retyear;
    }
};
