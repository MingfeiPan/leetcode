func isLongPressedName(name string, typed string) bool {
    for i, j := 0, 0; i < len(name); i++{
        if j == len(typed) {
            return false
        }
        if typed[j] != name[i] {
            //可能为重复导致不等, 先考虑确实不等的情况
            if j == 0 || typed[j] != typed[j-1] {
                return false
            }
            //去重
            cur := typed[j]
            for j < len(typed) && typed[j] == cur {
                j++
            }
            //去重后仍然不等
            if j == len(typed) || typed[j] != name[i] {
                return false
            }
        }
        j++
    }
    return true
}
