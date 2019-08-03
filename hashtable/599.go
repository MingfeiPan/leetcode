func findRestaurant(list1 []string, list2 []string) []string {
    s1 := make(map[string]int)
    s2 := make(map[string]int)
    
    var (
        i int
        v string
        max int
        ret []string
    )
    max = math.MaxInt32
    for i, v = range list1 {
        s1[v] = i
    }
    for i, v = range list2 {
        s2[v] = i
    }
    for v, i = range s1 {
        if i1, ok := s2[v]; ok {
            s1[v] += i1
            if s1[v] < max {
                max = s1[v]
            }
        }else {
            s1[v] = -1
        }
    }
    for v, i = range s1 {
        if i == max {
            ret = append(ret, v)
        }
    }
    return ret
}
