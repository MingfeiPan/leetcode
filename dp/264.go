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

func nthUglyNumber(n int) int {
    if n == 1 {
        return 1
    }
    var num2, num3, num5 int
    dp := make([]int , n)
    dp[0] = 1
    for i := 1; i < n; i++ {
        dp[i] = min(dp[num2]*2, dp[num3]*3, dp[num5]*5)
        if dp[i] == dp[num2]*2 {
            num2++
        }
        if dp[i] == dp[num3]*3 {
            num3++
        }
        if dp[i] == dp[num5]*5 {
            num5++
        }
     }
    return dp[n-1]
}

func min(a int, b int, c int) int {
    if a < b {
        if a < c {
            return a
        }else {
            return c
        }
    }else {
        if b < c {
            return b
        }else {
            return c
        }
    }
}
