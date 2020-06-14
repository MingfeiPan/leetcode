func findLeastNumOfUniqueInts(arr []int, k int) int {
    m := make(map[int]int)
    for _, v := range arr {
        if _, ok := m[v]; ok {
            m[v]++
        }else {
            m[v] = 1
        }
    }
    indexList := make([]int, 0)
    for _, v := range m {
        indexList = append(indexList, v)
    }
    sort.Ints(indexList)
    for len(indexList) > 0 && k >= indexList[0] {
        k = k - indexList[0]
        indexList = indexList[1:]
    }
    return len(indexList)
    
}
