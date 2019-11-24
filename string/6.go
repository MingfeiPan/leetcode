func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }
    ret := make([]string, numRows)
    var rowindex int
    var direct bool
    for _, c := range s {
        ret[rowindex] += string(c)
        if rowindex == 0 || rowindex == numRows - 1 {
            direct = !direct
        }
        if direct {
            rowindex++
        }else {
            rowindex--
        }
    }
    var output string
    for _, s := range ret {
        output += s
    }
    
    return output
}
