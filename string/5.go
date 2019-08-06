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
