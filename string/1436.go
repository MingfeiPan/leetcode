func destCity(paths [][]string) string {
    sourceMap := make(map[string]struct{})
    for _, pair := range paths {
        sourceMap[pair[0]] = struct{}{}
    }
    for _, pair := range paths {
        if _, ok := sourceMap[pair[1]]; !ok {
            return pair[1]
        }
    }
    return ""
}
