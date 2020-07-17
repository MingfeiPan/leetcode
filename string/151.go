func reverseWords(s string) string {
    ret := make([][]byte, 0)
    for i := 0; i < len(s); {
        temp := make([]byte, 0)
        for i < len(s) && s[i] != ' '{
            temp = append(temp, s[i])
            i++
        }
        i++
        if len(temp) > 0 {
            ret = append(ret, temp)    
        }
    }
    fmt.Println(ret)
    s = ""
    for i := len(ret)-1; i >= 0; i-- {
        s += string(ret[i])
        if i != 0 {
            s += " "
        }
    }
    return s
}

