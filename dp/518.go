func change(amount int, coins []int) int {
    dp := make([]int, amount+1)
    // for i, _ := range dp {
    //     dp[i] = 
    // }
    dp[0] = 1
    //注意外层循环为coin, 否则答案会有重复
    for _, coin := range coins {
        for i := 0; i <= amount; i++ {
            if i >= coin {
                dp[i] += dp[i-coin]
            }
        }
    }
    return dp[amount]
}
