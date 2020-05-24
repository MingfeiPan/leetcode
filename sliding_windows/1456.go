func maxVowels(s string, k int) int {
    var start, end, ret, cur int
    for end < len(s) {
        for end - start < k {
            if check(s[end]) {
                cur++
                if cur > ret {
                    ret = cur
                }
            }
            end++
        }
        if check(s[start]) {
            cur--
        }
        start++
    }
    return ret
}

func check(letter byte) bool {
    if letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' {
        return true
    }
    return false
}
