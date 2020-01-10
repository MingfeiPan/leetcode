func shortestPalindrome(s string) string {
	var ret string
	for index := len(s) - 1; index >= 0; index-- {
		for i, j := 0, index; i <= j; i, j = i+1, j-1 {
			if s[i] != s[j] {
				break
			}
			if i == j || i+1 == j {
				ret = s
				for i := index + 1; i < len(s); i++ {
					ret = string(s[i]) + ret
				}
                return ret
			}
		}
	}    
    return ""
}
