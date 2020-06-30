func isPathCrossing(path string) bool {
    m := make(map[string]struct{})
    point := make([]int, 2)
    point[0] = 0
    point[1] = 0
    var key string
    key = strconv.Itoa(point[0]) + "," + strconv.Itoa(point[1])
    m[key] = struct{}{}
    for _, dir := range path {
        if dir == 'N' {
            point[1]++
            key = strconv.Itoa(point[0]) + "," + strconv.Itoa(point[1])
            if _, ok := m[key]; ok {
                return true
            }else {
                m[key] = struct{}{}
            }
        }else if dir == 'S' {
            fmt.Println(m)
            point[1]--
            key = strconv.Itoa(point[0]) + "," + strconv.Itoa(point[1])
            if _, ok := m[key]; ok {
                return true
            }else {
                m[key] = struct{}{}
            }            
        }else if dir == 'E' {
            point[0]++
            key = strconv.Itoa(point[0]) + "," + strconv.Itoa(point[1])
            if _, ok := m[key]; ok {
                return true
            }else {
                m[key] = struct{}{}
            }             
        }else {
            point[0]--
            key = strconv.Itoa(point[0]) + "," + strconv.Itoa(point[1])
            if _, ok := m[key]; ok {
                return true
            }else {
                m[key] = struct{}{}
            }             
        }
    }
    return false
}
