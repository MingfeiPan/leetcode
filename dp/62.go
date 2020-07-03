uniquePaths(m int, n int) int {
    var ret int
    dp := make([][]int, n)
    for i, _ := range dp {
        dp[i] = make([]int, m)
    }
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if i == 0 || j == 0 {
                dp[i][j] = 1
            }else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
            if ret < dp[i][j] {
                ret = dp[i][j]
            }            
        }
    }
    return ret
}
