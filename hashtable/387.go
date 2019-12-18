func firstUniqChar(s string) int {
    m := make(map[byte]int)
    for i := 0; i < len(s); i++ {
        if _, ok := m[s[i]]; !ok {
            m[s[i]] = i
        }else {
            m[s[i]] = -1
        }
    }

    ret := math.MaxInt32
    for _, index := range m {
        if index >= 0 && index < ret {
            ret = index
        }
    }
    if ret == math.MaxInt32 {
        return -1
    }
    return ret
}
