func minCut(s string) int {
    dp := make([][]bool, len(s))
    for i, _ := range dp {
        dp[i] = make([]bool, len(s))
    }
    // for i := 0; i < len(s); i++ {
    //     dp[i][i] = true
    // }
    // dp[i][j] 表示s[i][j] 是否palindrome, 注意构建dp的顺序从间距从小到大, 这样才能复用前值
    for interval := 1; interval <= len(s); interval++ {
        for i := 0; i < len(s)-interval+1; i++ {
            j := i+interval-1
            if interval == 1 {
                dp[i][j] = true
            }else if interval == 2 {
                dp[i][j] = s[i] == s[j]
            }else {
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1]
            }
        }
    }
    ret := make([]int, len(s))
    for i := 0; i < len(s); i++ {
        if dp[0][i] {
            ret[i] = 0
        }else {
            ret[i] = len(s)
            for j := 0; j < i; j++ {
                // 可以在j处分开做规划, 即ret[0:i] = ret[0:j] + 1 + ret[j+1:i]
                if dp[j+1][i] && ret[j] + 1 < ret[i] {
                    ret[i] = ret[j] + 1
                }
            }
        }
    }
    fmt.Println(ret)
    return ret[len(s)-1]
}
