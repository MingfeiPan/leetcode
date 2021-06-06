class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (check(mat, target))
            return true;        
        rotate(mat);
        if (check(mat, target))
            return true;
        rotate(mat);
        if (check(mat, target))
            return true;
        rotate(mat);
        if (check(mat, target))
            return true;
        return false;
    }
private:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int length = matrix.size();
        for(int i=0; i<=length/2; ++i) {
            for(int j=i; j<length-i-1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[length-1-j][i];
                matrix[length-1-j][i] = matrix[length-1-i][length-1-j];
                matrix[length-1-i][length-1-j] = matrix[j][length-1-i];
                matrix[j][length-1-i] = temp;
            }
        }        
    }
    
    bool check(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& target) {
        int length = matrix.size();
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if (matrix[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
};
