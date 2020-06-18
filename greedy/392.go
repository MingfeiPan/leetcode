func isSubsequence(s string, t string) bool {
    var indexS, indexT int
    for indexT <= len(t) {
        if indexS == len(s) {
            return true
        }
        if indexT < len(t) && s[indexS] == t[indexT] {
            indexS++
            indexT++
        }else {
            indexT++
        }
    }
    return false
}
