func nthUglyNumber(n int) int {
    if n == 1 {
        return 1
    }
    dp := make([]int, n)
    p2, p3, p5 := 0, 0, 0
    dp[0] = 1
    for i := 1; i < n; i++ {
        dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5))
        
        //每一个都要判断是否+1, 因为类似15这种3*5的需要对于3跟5都+1, 避免重复选择
        if dp[i] == dp[p2]*2 {
            p2++
        }
        if dp[i] == dp[p3]*3 {
            p3++
        }
        if dp[i] == dp[p5]*5 {
            p5++
        }
    } 
    return dp[n-1]
}

func min(i int, j int) int {
    if i < j {
        return i
    }else {
        return j
    }
}
