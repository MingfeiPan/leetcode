wordSubsets(A []string, B []string) []string {
    mapB := make(map[rune]int, 0)
    //preprocess B
    for _, str := range B {
        tempB := make(map[rune]int, 0)
        for _, c := range str {
            if _, ok := tempB[c]; !ok {
                tempB[c] = 1
            }else {
                tempB[c]++
            }
        }
        // check mapB with tempB
        for key, _ := range tempB {
            if _, ok := mapB[key]; !ok {
                mapB[key] = tempB[key]
            }else {
                if mapB[key] < tempB[key] {
                    mapB[key] = tempB[key]
                }
            }
        }
    }
    ret := make([]string, 0)
    var flag bool
    for _, str := range A {
        flag = true
        mapstr := make(map[rune]int, 0)
        for _, c := range str {
            if _, ok := mapstr[c]; !ok {
                mapstr[c] = 1
            }else {
                mapstr[c]++
            }
        }
        // check
        for key, _ := range mapB {
            if _, ok := mapstr[key]; !ok {
                flag = false
                break
            }else {
                if mapstr[key] < mapB[key] {
                    flag = false
                    break
                }
            }
        }
        if flag {
            ret = append(ret, str)
        }
    }
    return ret
}
