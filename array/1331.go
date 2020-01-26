func arrayRankTransform(arr []int) []int {
    newArr := make([]int, len(arr))
    copy(newArr, arr)
    sort.Ints(newArr)
    m := make(map[int]int)
    index := 1
    for i := 0; i < len(newArr); i++ {
        if _, ok := m[newArr[i]]; !ok {
            m[newArr[i]] = index
            index++
        }
    }
    ret := make([]int, len(arr))
    for i := 0; i < len(arr); i++ {
        ret[i] = m[arr[i]]
    }
    return ret
}    
