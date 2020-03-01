// import "sort"

type Item struct{
    char rune
    rank []int
}

type ItemSlice []Item

func (slice ItemSlice) Len() int{
    return len(slice)
}

func (slice ItemSlice) Swap(i, j int) {
    slice[i], slice[j] = slice[j], slice[i]
}

func (slice ItemSlice) Less(i, j int) bool {
    for index := 0; index < len(slice[i].rank); index++ {
        if slice[i].rank[index] != slice[j].rank[index] {
            return slice[i].rank[index] > slice[j].rank[index]
        }
    }
    return slice[i].char < slice[j].char
}

func rankTeams(votes []string) string {
    m := make(map[rune][]int)
    for _, s := range votes {
        for i, char := range s {
            if _, ok := m[char]; !ok {
                m[char] = make([]int, len(s))
                m[char][i] += 1
            }else {
                m[char][i] += 1
            }
        }
    }
    arr := make(ItemSlice, 0)
    for char, rank := range m {
        arr = append(arr, Item{char, rank})
    }
    sort.Sort(arr)
    var ret string
    for i, _ := range arr {
        ret += string(arr[i].char)
    }
    return ret
}
