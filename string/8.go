func myAtoi(str string) int {
    var (
        signFlag bool
        ret = 0
        index int
        length = len(str)
    )
    
    for index < length && str[index] == ' ' {
        index++
    }
    
    if index < length && str[index] == '-' {
        signFlag = true
        index++
    }else if index < length && str[index] == '+' {
        index++
    }
    for index < length && str[index] <= 57 && str[index] >= 48 && ret < math.MaxInt32{
        ret *= 10
        ret += int(str[index]) - 48
        index++
    }
    if signFlag {
        ret = -ret
    }
    if ret > math.MaxInt32 {
        return math.MaxInt32
    }else if ret < math.MinInt32 {
        return math.MinInt32
    }
    return ret
}
