//利用回文的特性
func longestPalindrome(s string) string {
    if s == "" {
        return s
    }
    var left, right int  
    ret := string(s[0])
    for i := 0; i < len(s) - 1; i++ {
        left = i
        right = i
        for left > 0 && right < len(s) - 1 && s[left-1] == s[right+1] {
            left--
            right++
        }
        if len(ret) < right - left + 1 {
            ret = s[left:right+1]
        }
        if s[i] == s[i+1] {
            left = i
            right = i + 1
            for left > 0 && right < len(s) - 1 && s[left-1] == s[right+1] {
                left--
                right++
            }
            if len(ret) < right - left + 1 {
                ret = s[left:right+1]
            }            
        }
        
    }
    return ret
}

func longestPalindrome(s string) string {
    if s == "" {
        return s
    }
    dp := make([][]int, len(s))
    for i, _ := range dp {
        dp[i] = make([]int, len(s))
    }
    var start, end int
    for i := len(s)-1; i >= 0; i-- {
        for j := i; j < len(s); j++ {
            if s[i] == s[j] {
                if j - i < 3 {
                    dp[i][j] = j - i + 1
                }else {
                    if dp[i+1][j-1] > 0 {
                        dp[i][j] = dp[i+1][j-1] + 2    
                    }
                }
                if dp[i][j] > end - start {
                    start = i
                    end = j
                }
            }
        }
    }
    return s[start:end+1]
}
