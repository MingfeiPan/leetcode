// slow one
func lengthOfLongestSubstring(s string) int {
    var start, cur, ret int
    var m map[byte]int
    for start = 0; start < len(s); {
        m = make(map[byte]int, 0)
        cur = start
        for cur < len(s) {
            if _, ok := m[s[cur]]; !ok {
                m[s[cur]] = 1
                cur++
                if cur == len(s) {
                    if ret < cur - start {
                        ret = cur - start
                    }
                }
            }else {
                if ret < cur - start {
                    ret = cur - start
                }
                break
            }
        }
        start++
    }
    return ret
}

// faster with two pointers
func lengthOfLongestSubstring(s string) int {
    var start, cur, ret int
    m := make(map[byte]int, 0)
    var dup byte
    for start < len(s) {
        for cur < len(s) {
            if _, ok := m[s[cur]]; !ok {
                m[s[cur]] = 1
                cur++
            }else {
                if m[s[cur]] == 0 {
                    m[s[cur]]++
                    cur++
                }else{
                    m[s[cur]]++
                    dup = s[cur]
                    break                    
                }
            }
        }
        if ret < cur - start {
            ret = cur - start
        }
        for start < cur && start < len(s) {
            if s[start] != dup {
                m[s[start]]--
                start++
            }else {
                m[s[start]]--
                start++
                // 这里相当于找到了前一个重复的然后做了删除并start++, 所以要把cur++, 不然会死循环
                cur++
                break
            }
        }
    }
    return ret
}
