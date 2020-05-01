func backspaceCompare(S string, T string) bool {
    var countI, countJ, indexI, indexJ int
    indexI = len(S) - 1
    indexJ = len(T) - 1 
    for indexI >= 0 || indexJ >= 0 {
       
        for indexI >= 0 {
            if S[indexI] == '#' {
                indexI--
                countI++
            }else if countI > 0 {
                countI--
                indexI--
            } else {
                break
            }
        }
        
        for indexJ >= 0 {
            if T[indexJ] == '#' {
                indexJ--
                countJ++
            } else if countJ > 0 {
                countJ--
                indexJ--
            } else {
                break
            }
        }

        if indexI >= 0 && indexJ >= 0 && S[indexI] != T[indexJ] {
            return false
        }        
        // when S is empty and T is not 
        if (indexJ < 0 && indexI >= 0) || (indexI < 0 && indexJ >= 0) {
            return false
        }      
        indexI--
        indexJ--
    }
    return true
    
}
