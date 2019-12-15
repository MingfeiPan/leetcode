func sequentialDigits(low int, high int) []int {
    lowbit := getbits(low)
    highbit := getbits(high)
    ret := make([]int, 0)
    for i := lowbit; i <= highbit; i++ {
        for j := 1; j < 9; j++ {
            temp := make([]int, 0)
            index := i
            step := j
            for index > 0 {
                if step <= 9 {
                    temp = append(temp, step)    
                }
                step++
                index--
            }
            num := getnum(temp)
            if num >= low && num <= high && len(temp) == i {
                ret = append(ret, num)
            }
        }
    }
    return ret
}

func getnum(nums []int) int {
    var ret int
    for i := 0; i < len(nums); i++ {
        ret = ret*10 + nums[i]
    }
    return ret
}
func getbits(num int) int {
    var ret int
    for num > 0 {
        num = num / 10
        ret++
    }
    return ret
}
