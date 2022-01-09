class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            std::vector<int> check(matrix.size()+1, 0);
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (check[matrix[i][j]] == 1) return false;
                check[matrix[i][j]] = 1;
            }
        }
        
        for (int j = 0; j < matrix[0].size(); ++j) {
            std::vector<int> check(matrix.size()+1, 0);
            for (int i = 0; i < matrix.size(); ++i) {
                if (check[matrix[i][j]] == 1) return false;
                check[matrix[i][j]] = 1;                
            }
        }
        return true;
    }
};
