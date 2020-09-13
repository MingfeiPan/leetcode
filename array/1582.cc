class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ret = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                bool flag = false;
                if (mat[i][j] == 1) {
                    if (checkSingle(mat, i, j)) {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
    bool checkSingle(vector<vector<int>>& mat, int m, int n) {
        for(int i = 0; i < mat.size(); i++) {
            if (i == m) {
                continue;
            }
            if (mat[i][n] == 1) {
                return false;
            }
        }
        for (int i = 0; i < mat[0].size(); i++) {
            if (i == n) {
                continue;
            }
            if (mat[m][i] == 1) {
                return false;
            }
        }
        return true;
    }
};
