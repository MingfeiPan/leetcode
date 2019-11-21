func lengthOfLastWord(s string) int {
    length := len(s)
    var flag bool
    var lengthEndSpace int
    for i := length - 1; i >= 0; i-- {
        if s[i] == ' ' {
            if flag {
                return length - i - 1 - lengthEndSpace   
            }else {
                lengthEndSpace++
            }
        }else {
            flag = true
        }
    }
    return length - lengthEndSpace
}
