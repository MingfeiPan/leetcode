func groupThePeople(groupSizes []int) [][]int {
    ret := make([][]int, 0)
    mapper := make(map[int][]int)
    for i, size := range groupSizes {
        if _, ok := mapper[size]; !ok {
            newGroup := make([]int, 0)
            newGroup = append(newGroup, i)
            mapper[size] = newGroup
            
        }else {
            mapper[size] = append(mapper[size], i)
        }
        if len(mapper[size]) == size {
            ret = append(ret, mapper[size])
            mapper[size] = make([]int, 0)
        }        
    }
    return ret
}
