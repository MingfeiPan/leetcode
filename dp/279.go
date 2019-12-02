func numSquares(n int) int {
    dp := make([]int, n+1)
    for i := 1; i <= n; i++ {
        dp[i] = n
        for j := 1; j*j <= n; j++ {
            if i - j*j >= 0 {
                dp[i] = min(dp[i], dp[i-j*j]+1)
            }
        }
    }
    return dp[n]
}

func min(i int, j int) int {
    if i < j {
        return i
    }else {
        return j
    }
}
