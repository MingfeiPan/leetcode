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

type Item struct {
    count int
    index int
}
func firstUniqChar(s string) int {
    m := make(map[rune]*Item)
    for i, c := range s {
        if _, ok := m[c]; ok {
            m[c].count++    
        }else {
            m[c] = &Item{1, i}
        }
    }
    for _, c := range s {
        if m[c].count == 1 {
            return m[c].index
        }
    }
    return -1
}
