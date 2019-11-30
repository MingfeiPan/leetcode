func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    var ret string
    var index int
    for index < len(strs[0]) {
        for i := 1; i < len(strs); i++ {
            if len(strs[i]) <= index || strs[0][index] != strs[i][index] {
                return ret
            }
        }
        ret += string(strs[0][index])
        index++
    }
    return ret
}
