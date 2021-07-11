class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c)
            return mat;
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        int index_r = 0, index_c = 0;
        for (const auto &line : mat) {
            for (const auto &num : line) {
                if (index_c < c) {
                    cur.emplace_back(num);
                    ++index_c;
                } else {
                    std::vector<int> temp;
                    cur.swap(temp);
                    ret.emplace_back(temp);
                    cur.emplace_back(num);
                    index_c = 1;   
                }
            }
        } 
        ret.emplace_back(cur);
        return ret;
    }
};
