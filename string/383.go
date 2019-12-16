func canConstruct(ransomNote string, magazine string) bool {
    m := make(map[rune]int)
    for _, c := range ransomNote {
        if _, ok := m[c]; !ok {
            m[c] = 1
        }else {
            m[c]++
        }
    }
    for _, c := range magazine {
        if i, ok := m[c]; ok {
            if i == 0 {
                continue
            }else {
                m[c]--
            }
        }
    }
    for _, c := range m {
        if c > 0 {
            return false
        }
    }
    return true
}
