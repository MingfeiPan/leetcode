func canConstruct(ransomNote string, magazine string) bool {
    ransomMap := make(map[rune]int)
    magazineMap := make(map[rune]int)
    for _, c := range ransomNote {
        if _, ok := ransomMap[c]; ok {
            ransomMap[c] += 1
        } else {
            ransomMap[c] = 1
        }
    }

    for _, c := range magazine {
        if _, ok := magazineMap[c]; ok {
            magazineMap[c] += 1
        } else {
            magazineMap[c] = 1
        }
    }    
    
    for k, v := range ransomMap {
        if count, ok := magazineMap[k]; !ok {
            return false
        } else {
            if count < v {
                return false
            }
        }
    }
    return true
}
