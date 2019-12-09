func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    var dup = x
    var newVal int
    for dup > 0 {
        newVal = dup % 10 + newVal * 10
        dup = dup / 10
    }
    return newVal == x
}
