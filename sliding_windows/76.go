func checkWindow(window map[byte]int) bool {
	for _, v := range window {
		if v < 0 {
			return false
		}
	}
	return true
}

func minWindow(s string, t string) string {
	window := make(map[byte]int, 0)
	for _, c := range t {
		if _, ok := window[byte(c)]; !ok {
			window[byte(c)] = -1
		} else {
			window[byte(c)]--
		}
	}
	var (
		i   int
		j   int
		ret string
	)

	for i <= j && j < len(s) {

		// move j right till found a result
		for i <= j && j < len(s) && !checkWindow(window) {
			if _, ok := window[s[j]]; ok {
				window[s[j]]++
			}
			j++
		}
		if !checkWindow(window) {
			break
		}
		// move i right till a result is unfulfilled, tricky here j <= len(s) or will miss last s[i:j]
		for i <= j && j <= len(s) && checkWindow(window) {
			if _, ok := window[s[i]]; ok {
				window[s[i]]--
			}
			i++
		}
		// fulfill the last result by moving i left
		window[s[i-1]]++
		i--
		if ret == "" {
			ret = s[i:j]
		} else {
			if j-i < len(ret) {
				ret = s[i:j]
			}
		}
		// find a answer, continue
		window[s[i]]--
		i++
	}
	return ret
}
