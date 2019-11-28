// O(n^3) TLE
func longestValidParentheses(s string) int {
    var ret int
    for i := 0; i < len(s); i++ {
        for j := i+1; j < len(s); j++ {
            if checkValid(s[i:j+1]) {
                if len(s[i:j+1]) > ret {
                    ret = len(s[i:j+1])
                }
            }
        }
    }
    return ret
}

func checkValid(s string) bool {
    stack := make([]byte, 0)
    var index int
    for index < len(s) {
        if s[index] == '(' {
            stack = append(stack, s[index])
        }else {
            if len(stack) > 0 && stack[len(stack)-1] == '(' {
                stack = stack[:len(stack)-1]
            }else {
                return false
            }
        }
        index++
    }
    if len(stack) > 0 {
        return false
    }
    return true
}


// dp
func longestValidParentheses(s string) int {
    dp := make([]int, len(s))
    for i := 1; i < len(s); i++{
        if s[i] == ')' {
            if s[i-1] == '(' {
                if i < 2 {
                    // init case
                    dp[i] = 2
                }else {
                    dp[i] = dp[i-2] + 2    
                }
            }else {
                if i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(' {
                    if i-dp[i-1]-2 >= 0 {
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2    
                    }else {
                        dp[i] = dp[i-1] + 2
                    }
                }
            }
        }
    }
    var ret int
    for _, v := range dp {
        if ret < v {
            ret = v
        }
    }
    return ret
}
