class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret;
        ret.emplace_back(std::vector<int>(1,1));
        for (int i = 1; i < numRows; ++i) {
            std::vector<int> cur(1,1);
            for (int j = 0; j < (i-1); ++j) {
                cur.emplace_back(ret[i-1][j] + ret[i-1][j+1]);
            }
            cur.emplace_back(1);
            ret.emplace_back(std::move(cur));
        }
        return ret;
    }
};
