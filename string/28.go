strStr(haystack string, needle string) int {
    if needle == "" {
        return 0
    }
	var curMatch string
	var matchLength int
	curIndex := -1
	for i := 0; i < len(haystack); {
		for j := 0; j < len(needle); {
			if i == len(haystack) {
				fmt.Println(curMatch)
				//end of haystack
				return -1
			}
			if haystack[i] == needle[j] {
				curIndex = i
				curMatch += string(needle[j])
				//find a match
				if curMatch == needle {
					return curIndex - len(needle) + 1
				}
				i++
				j++
			} else {
				if curMatch == "" {
					i++
				} else {
					matchLength = findPartialMatch(curMatch)
					fmt.Println(curMatch)
					j -= len(curMatch) - matchLength
					// i += len(curMatch) - matchLength
					curMatch = curMatch[:matchLength]
				}
			}
		}
	}
	return -1
}

func findPartialMatch(s string) int {
	var matchLength int
	for i := 1; i < len(s); i++ {
		if s[0:i] == s[len(s)-i:len(s)] {
			matchLength = i
		}
		//fmt.Println("prefix ", s[0:i])
		//fmt.Println("postfix ", s[len(s)-i:len(s)])
	}
	return matchLength
}
