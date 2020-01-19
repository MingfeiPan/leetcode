func maximum69Number (num int) int {
    var cur int
    l := make([]int, 0)
    for num > 0 {
        cur = num % 10
        num = num / 10
        l = append(l, cur)
    }
    for i := len(l)-1; i >= 0; i-- {
        if l[i] == 6 {
            l[i] = 9
            break
        }
    }
    num = 0
    for i := len(l)-1; i >= 0; i-- {
        num = num * 10 + l[i]
    }
    return num
}
