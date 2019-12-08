func validPalindrome(s string) bool {
    if len(s) <= 1 {
        return true
    }
    if s[0] == s[len(s)-1] {
        return validPalindrome(s[1:len(s)-1]) 
    }else {
        // 一次删除机会
        return directCheck(s[1:]) || directCheck(s[:len(s)-1])
    }
}

func directCheck(s string) bool {
    if len(s) <= 1 {
        return true
    }
    if s[0] == s[len(s)-1] {
        return directCheck(s[1:len(s)-1]) 
    }
    return false
}

func directCheck(s string) bool {
    for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
        if s[i] != s[j] {
            return false
        }        
    }
    return true   
}
