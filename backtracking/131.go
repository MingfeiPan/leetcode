func partition(s string) [][]string {
    ret := make([][]string, 0)
    if s == "" {
        return ret
    }
    dfs(&ret, 0, s, []string{})
    return ret
}

func dfs(ret *[][]string, start int, origin string, cur []string) {
    if start == len(origin) {
        *ret = append(*ret, append([]string{}, cur...))
        return
    }
    for i := start+1; i <= len(origin); i++ {
        // 对于每一个正确的prefix, dfs剩余的string
        if isPalindrome(origin[start:i]) {
            temp := append(append([]string{}, cur...), origin[start:i])
            dfs(ret, i, origin, temp)
        }
    }
}

func isPalindrome(s string) bool {
    for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
        if s[i] != s[j] {
            return false
        }
    }
    return true 
}
