class Solution {

public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        std::unordered_set<std::string> s;
        for (const auto& d : dig) {
            s.emplace(std::to_string(d[0]) + ',' + std::to_string(d[1]));
        }
        bool flag = true;
        int ret = 0;
        for (const auto& art : artifacts) {
            flag = true;
            for (int i = art[0]; i <= art[2]; ++i) {
                for (int j = art[1]; j <= art[3]; ++j) {
                    if (!s.count(std::to_string(i) + ',' + std::to_string(j))) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) ++ret;
        }
        return ret;
    }
};
