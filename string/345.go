func reverseVowels(s string) string {
    bs := []byte(s)
    bt := "aeiouAEIOU"
    
    for i, j := 0, len(s) - 1; i < j; i, j = i+1, j-1 {
        for i < j {
            if strings.Contains(bt, string(bs[i])) {
                break
            }else {
                i++
            }
        }
        if i == j {
            return string(bs[:])
        }
        for i < j {
            if strings.Contains(bt, string(bs[j])) {
                break
            }else {
                j--
            }
        }
        if i == j {
            return string(bs[:])
        }
        bs[i], bs[j] = bs[j], bs[i]
    }
    return string(bs[:])
}
