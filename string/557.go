func reverseWords(s string) string {
    bs := []byte(s)
    var flag byte
    flag = ' '
    var i, j int
    for i = 0; i < len(bs); i++ {
        if bs[i] == flag {
            reverse(&bs, i+j, i-1)
            j = 0
        }else {
            j--
        }
    }
    if j != 0 {
        reverse(&bs, i+j, i-1)
    }
    return string(bs[:])
    
}

func reverse(s *[]byte, start int, end int) {
    for i, j := start, end; i < j; i, j = i+1, j-1 {
        (*s)[i], (*s)[j] = (*s)[j], (*s)[i]
    }
}
