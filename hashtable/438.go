func findAnagrams(s string, p string) []int {
    target := make(map[byte]int)
    ret := make([]int, 0)
    var counter int
    for i := 0; i < len(p); i++ {
        if _, ok := target[p[i]]; ok {
            target[p[i]]++
        }else {
            target[p[i]] = 1
            counter++
        }
    }
    
    var start, end int
    for end < len(s) {
        if _, ok := target[s[end]]; ok {
            target[s[end]]--
            if target[s[end]] == 0 {
                counter--
            }
        }
        end++
        
        for counter == 0 {
            if _, ok := target[s[start]]; ok {
                target[s[start]]++
                if target[s[start]] > 0 {
                    counter++
                }
            }
            if end - start == len(p) {
                ret = append(ret, start)
            }
            start++
        }
    }
    return ret
}
