func isPalindrome(s string) bool {
    bs := bytes.ToLower([]byte(s))
    i , j := 0, len(bs)-1
    for i < j {
        
        for i < j && (bs[i] < 'a' || bs[i] > 'z') && (bs[i] < '0' || bs[i] > '9') {
            i++
        }
        for i < j && (bs[j] < 'a' || bs[j] > 'z') && (bs[j] < '0' || bs[j] > '9') {
            j--
        }

        if i < j && bs[i] != bs[j] {
            return false
        }
        i++
        j--
    }
    return true
}
