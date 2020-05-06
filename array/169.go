func majorityElement(nums []int) int {
    ht := make(map[int]int)
    mark := len(nums) / 2
    for _, v := range nums {
        if count, ok := ht[v]; !ok {
            ht[v] = 1
        }else {
            ht[v]++
            if count + 1 > mark {
                return v
            }
        }
    }
    
    return nums[0]
}

func majorityElement(nums []int) int {
    var (
        num int
        count int
    )
    for _, v := range nums {
        if count == 0 {
            num = v
            count++
        }else {
            if num == v {
                count++
            }else {
                count--
            }
        }
    }
    return num
}

func majorityElement(nums []int) int {
    if len(nums) == 1 {
        return nums[0]
    }
    length := len(nums) / 2
    m := make(map[int]int)
    for _, num := range nums {
        if c, ok := m[num]; !ok {
            m[num] = 1
        }else {
            if c >= length {
                return num
            }
            m[num]++
        }
    }
    return -1
}
