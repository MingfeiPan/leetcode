func longestPalindromeSubseq(s string) int {
    if s == "" {
        return 0
    }
    dp := make([][]int, len(s))
    for i, _ := range dp {
        dp[i] = make([]int, len(s))
    }
    var ret int
    for i := len(s)-1; i >= 0; i-- {
        for j := i; j < len(s); j++ {
            if s[i] == s[j] {
                if j - i < 3 {
                    dp[i][j] = j - i + 1
                }else {
                    dp[i][j] = dp[i+1][j-1] + 2
                }
                if dp[i][j] > ret {
                    ret = dp[i][j]
                }
            }else {
                // 注意这里的微小区别 区分substring跟subsequence
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
            }
        }
    }
    return ret
}

func max(i int, j int) int {
    if i > j {
        return i
    }else {
        return j
    }
}
