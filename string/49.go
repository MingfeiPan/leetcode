func groupAnagrams(strs []string) [][]string {
	var key string
	mapret := make(map[string][]string, 0)
	listret := make([][]string, 0)

	for _, s := range strs {
		key = makeKey(s)
		if _, ok := mapret[key]; !ok {
			mapret[key] = make([]string, 0)
		}
		mapret[key] = append(mapret[key], s)
	}

	for _, v := range mapret {
		listret = append(listret, v)
	}
	return listret    
}

func makeKey(s string) string {
	var temps []string
	var ret string
	for _, c := range s {
		temps = append(temps, string(c))
	}
	sort.Strings(temps)
	for _, c := range temps {
		ret += c
	}
	return ret
}

