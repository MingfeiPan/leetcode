func reverseOnlyLetters(S string) string {
    var left, right int
    left = 0
    right = len(S) - 1
    byteS := []byte(S)
    for left < right {
        for (byteS[left] < 'a' || byteS[left] > 'z') && (byteS[left] < 'A' || byteS[left] > 'Z') && left < right {
            left++
        }
        for (byteS[right] < 'a' || byteS[right] > 'z') && (byteS[right] < 'A' || byteS[right] > 'Z') && left < right {
            right--
        }
        byteS[left], byteS[right] = byteS[right], byteS[left]
        left++
        right--
    }
    return string(byteS)
}
