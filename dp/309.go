func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }
    if len(prices) == 1 {
        return 0
    }
    dp := make([][]int, len(prices))
    for i, _ := range dp {
        dp[i] = make([]int, 2)
    }
    // dp table 决定第i天是否持有或者不持有股票0表示不持有股票 1表示持有股票
    // 手动计算前两天数据
    dp[0][0] = 0
    dp[0][1] = -prices[0]
    dp[1][0] = max(dp[0][0], dp[0][1] + prices[1])
    dp[1][1] = max(dp[0][1], -prices[1])
    for i := 2; i < len(dp); i++ {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
        dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
    }
    return dp[len(prices)-1][0]
}

func max(a int, b int) int {
    if a < b {
        return b
    }else {
        return a
    }
}
