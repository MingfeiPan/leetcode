//这个题可以巧妙利用kmp next table的性质, 前缀后缀相同子串即是重复的子串, next[i]是i位置之前重合部分的长度值, 如果一个字符串是长度为3的子串重复4次, 那么next表的结尾一定是9
func repeatedSubstringPattern(s string) bool {
    next := make([]int, len(s))
    var j int
    for i := 1; i < len(s); {
        if s[i] == s[j] {
            next[i] = j + 1
            i++
            j++
        }else {
            if j > 0 {
                j = next[j-1]
            }else {
                next[i] = 0
                i++
            }
        }
    }
    //如果next结尾大于0而且与len的差值可以被len整除
    return next[len(s) - 1] > 0 && len(s) % (len(s) - next[len(s)-1]) == 0

}
