func maxProfit(prices []int) int {
    
    if len(prices) == 0 {
        return 0
    }
    ret := 0
    curlow := prices[0]
    for i := 1; i < len(prices); i++ {
        if prices[i] - curlow > ret {
            ret = prices[i] - curlow
        }
        if prices[i] < curlow {
            curlow = prices[i]
        }
    }
    return ret
}


func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }
    dp := make([][]int, len(prices))
    for i, _ := range dp {
        dp[i] = make([]int, 2)
    }
    // 0表示未持有 1表示持有
    dp[0][0] = 0
    dp[0][1] = -prices[0]
    for i := 1; i < len(prices); i++ {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
        dp[i][1] = max(dp[i-1][1], -prices[i])
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
