reverseStr(s string, k int) string {
    
    bs := []byte(s)
    for i := 0; i < len(bs); i += 2 * k {
        if (i+k-1) >= len(bs) {
            reverse(&bs, i, len(bs)-1)
        }else{
            reverse(&bs, i, i+k-1)     
        }   
    }  
    return string(bs[:])
}

func reverse(s *[]byte, start int, end int) {
    for i, j := start, end; i < j; i, j = i+1, j-1 {
        (*s)[i], (*s)[j] = (*s)[j], (*s)[i]    
    }
}


