func checkIfExist(arr []int) bool {
    m := make(map[int]struct{})
    for _, i := range arr {
        if _, ok := m[i]; !ok {
            m[i*2] = struct{}{}
            if i % 2 == 0 {
                m[i / 2] = struct{}{}
            }
        }else {
            return true
        }
    }
    return false
}
