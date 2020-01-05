func freqAlphabets(s string) string {
    var ret string
    for i := len(s)-1; i >= 0; {
        if s[i] == '#' {
            ret = string(byte(int(s[i-2]-48)*10+int(s[i-1]-48)+96)) + ret
            i -= 3
        }else {
            ret = string(byte(int(s[i]-48)+96)) + ret
            i--
        }
    }
    return ret
}
