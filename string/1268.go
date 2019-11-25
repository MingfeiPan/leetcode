func suggestedProducts(products []string, searchWord string) [][]string {
    ret := make([][]string, 0)
    var temp []string
    for i := 1; i <= len(searchWord); i++ {
        temp = make([]string, 0)
        for _, word := range products {
            if i <= len(word) && searchWord[:i] == word[:i] {
                temp = append(temp, word)
            }
        }
        sort.Strings(temp)
        if len(temp) < 3 {
            ret = append(ret, append([]string{}, temp...))
        }else {
            ret = append(ret, append([]string{}, temp[:3]...))
        }
    }
    return ret
}


