func findTheDifference(s string, t string) byte {
    m := make(map[rune]int)
    for _, c := range s {
        if _, ok := m[c]; ok {
            m[c]++
        } else {
            m[c] = 1
        }
    }
    for _, c := range t {
        if _, ok := m[c]; !ok {
            return byte(c)
        }else {
            m[c]--
            if m[c] < 0 {
                return byte(c)
            }
        }
    }
    return 'a'
}
