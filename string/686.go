func repeatedStringMatch(A string, B string) int {
    var s string
    for len(s) < len(B) {
        s += A
    }
    if strings.Contains(s, B) {
        return len(s) / len(A)
    }
    s += A
    if strings.Contains(s, B) {
        return len(s) / len(A)
    }
    return -1
}
