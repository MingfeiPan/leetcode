import "strings"
func wordPattern(pattern string, str string) bool {
    strs := strings.Split(str, " ")
    if len(strs) != len(pattern) {
        return false
    }
    m := make(map[string]int)
    for i := 0; i < len(pattern); i++ {
        s1 := "pattern"+string(pattern[i])
        s2 := "word"+strs[i]
        if _, ok := m[s1]; !ok{
            m[s1] = i
        }
        if _, ok := m[s2]; !ok {
            m[s2] = i
        }
        if m[s1] != m[s2] {
            return false
        }
    }
    return true
}
