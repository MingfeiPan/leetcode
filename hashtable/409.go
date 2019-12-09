func longestPalindrome(s string) int {
    m := make(map[rune]int)
    var ret int
    var flag bool
    for _, c := range s {
        if _, ok := m[c]; !ok {
            m[c] = 1
        }else {
            m[c]++
        }
    }
    for _, v := range m {
        if !flag {
            if v % 2 == 1 {
                flag = true
            }
        }
        ret += v / 2 * 2
    }
    if flag {
        ret++
    }
    return ret
}
