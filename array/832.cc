class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            std::reverse(row.begin(), row.end());
            for (auto& i: row) {
                i ^= 1;
            }
        }
        return A;
    }
};
