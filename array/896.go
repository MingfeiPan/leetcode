func isMonotonic(A []int) bool {
    if len(A) == 1 {
        return true
    }
    flag1 := false
    flag2 := false
    var i int
    if A[0] <= A[1] {
        for i = 1; i < len(A)-1; {
            if A[i] > A[i+1] {
                flag1 = false
                break
            }else {
                i++
            }
        }
    }
    if i == len(A)-1 {
        flag1 = true
    }
    if A[0] >= A[1] {
        for i = 1; i < len(A)-1; {
            if A[i] < A[i+1] {
                flag2 = false
                break
            }else {
                i++
            }
        }        
    }
    if i == len(A)-1 {
        flag2 = true
    }
    if flag1 || flag2 {
        return true
    }else {
        return false
    }
}
