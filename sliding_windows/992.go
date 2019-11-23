// tle
func subarraysWithKDistinct(A []int, K int) int {
    var i, j, ret int
    var m map[int]int
    for i = 0; i < len(A); i++ {
        m = make(map[int]int, 0)
        for j = i; j < len(A); j++ {
            if _, ok := m[A[j]]; !ok {
                m[A[j]] = 1
            }
            if len(m) == K {
                ret++
            }
        }
    }
    return ret
}

// with tricky
func subarraysWithKDistinct(A []int, K int) int {
    return subarrayWithMostKDistinct(A, K) - subarrayWithMostKDistinct(A,K-1)
}

func subarrayWithMostKDistinct(A []int, K int) int {
    var right, left, ret int
    m := make(map[int]int, 0)
    for right = 0; right < len(A); right++ {
        if _, ok := m[A[right]]; ok {
            m[A[right]]++         
        }else {
            m[A[right]] = 1           
        }
        for len(m) > K {
            if cur, ok := m[A[left]]; ok {
                if cur > 1 {
                    m[A[left]]--
                }else {
                    delete(m, A[left])
                }
                left++
            } 
        }
        ret += right - left + 1
    }
    return ret
}
