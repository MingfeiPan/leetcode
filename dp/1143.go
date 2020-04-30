func longestCommonSubsequence(text1 string, text2 string) int {
    length1 := len(text1)
    length2 := len(text2)
    ret := make([][]int, length1+1)
    for i, _ := range ret {
        ret[i] = make([]int, length2+1)
    }
    for i := 0; i <= length1; i++ {
        for j := 0; j <= length2; j++ {
            if i == 0 || j == 0 {
                ret[i][j] = 0
            }else if text1[i-1] == text2[j-1] {
                ret[i][j] = ret[i-1][j-1] + 1
            }else {
                if ret[i-1][j] > ret[i][j-1] {
                    ret[i][j] = ret[i-1][j]
                }else {
                    ret[i][j] = ret[i][j-1]
                }
            }
        }
    }
    return ret[length1][length2]
}

func longestCommonSubsequence(text1 string, text2 string) int {
    dp := make([][]int, len(text1)+1)
    for i,_ := range dp {
        dp[i] = make([]int, len(text2)+1)
    }
    for i := 0; i <= len(text1); i++ {
        for j := 0; j <= len(text2); j++ {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
            } else {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
                }
            }
        }
    }
    return dp[len(text1)][len(text2)]
}

func max(i1 int, i2 int, i3 int) int {
    if i1 < i2 {
        if i2 < i3 {
            return i3
        }else {
            return i2
        }
    }else {
        if i1 < i3 {
            return i3
        }else {
            return i1;
        }
    }
}
