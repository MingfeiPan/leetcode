func countSubstrings(s string) int {
    var ret int
    for index := 0; index < len(s); index++ {
        for i, j := index, index+1; i >= 0 && j < len(s); i, j = i-1, j+1 {
            if s[i] == s[j] {
                ret++
            }else {
                break
            }
        }
        ret++
        for i, j := index-1, index+1; i >= 0 && j < len(s); i, j = i-1, j+1 {
            if s[i] == s[j] {
                ret++
            }else {
                break
            }
        }
    }
    return ret
}
