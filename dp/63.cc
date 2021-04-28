class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        int dp[obstacleGrid.size()][obstacleGrid[0].size()];
        for (size_t i = 0; i < obstacleGrid.size(); i++) {
            for (size_t j = 0; j < obstacleGrid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    if (obstacleGrid[i][j] == 1) {
                        return 0;
                    } else {
                        dp[i][j] = 1;
                    }
                } else if (i == 0 && j != 0) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                    } else {
                        if (obstacleGrid[i][j-1] == 1) {
                            dp[i][j] = 0;    
                        } else {
                            dp[i][j] = dp[i][j-1];
                        }
                    }                    
                } else if ( i != 0 && j == 0) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                    } else {
                        if (obstacleGrid[i-1][j] == 1) {
                            dp[i][j] = 0;    
                        } else {
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                } else {
                    dp[i][j] = 0;
                    if (obstacleGrid[i][j] != 1) {
                        if (obstacleGrid[i-1][j] != 1) {
                            dp[i][j] += dp[i-1][j];
                        }
                        if (obstacleGrid[i][j-1] != 1) {
                            dp[i][j] += dp[i][j-1];
                        }                        
                    }
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        std::vector<std::vector<int>> dp;
        for (size_t i = 0; i < obstacleGrid.size(); ++i) {
            std::vector<int> cur(obstacleGrid[i].size(), -1);
            dp.emplace_back(std::move(cur));
        }
        for (size_t i = 0; i < obstacleGrid.size(); ++i) {
            for (size_t j = 0; j < obstacleGrid[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : 1;
                } else if (i == 0 && j != 0) {
                    dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i][j-1];
                } else if (i != 0 && j == 0) {
                    dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j];
                } else {
                    dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : (dp[i][j-1] + dp[i-1][j]);
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
