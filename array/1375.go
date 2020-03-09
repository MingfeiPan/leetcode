func numTimesAllBlue(light []int) int {
    var ret int
    var flag bool
    l := make([]int, len(light))
    for _, i := range light {
        index := i - 1
        l[index] = 1;
        flag = true
        
        // 向左查
        for index >= 0 {
            if l[index] == 0 {
                flag = false
                break
            } 
            index--
        }
        
        if !flag {
            continue
        }
        // 向右查
        index = i - 1
        for index < len(l)-1 {
            if l[index] == 0 && l[index+1] == 1 {
                flag = false
                break
            }
            index++
        }
        if flag {
            // fmt.Println(l)
            ret++
        }
    }
    return ret
}
