
type Item struct{
    socount int
    index int
}

type itemSlice []*Item

func kWeakestRows(mat [][]int, k int) []int {
    ret := make([]int, k)
    items := make(itemSlice, len(mat))
    for index, _ := range mat {
        count := 0
        for _, v := range mat[index] {
            if v == 1 {
                count++
            }else {
                break
            }
        }
        items[index] = &Item{count, index}
    }
    sort.Sort(items)
    for index, _ := range ret {
        ret[index] = items[index].index
    }
    return ret
}

func (t itemSlice) Len() int {
    return len(t)
}

func (t itemSlice) Less(i, j int) bool {
    if t[i].socount == t[j].socount {
        return t[i].index < t[j].index
    }else {
        return t[i].socount < t[j].socount
    }
}

func (t itemSlice) Swap(i, j int) {
    t[i], t[j] = t[j], t[i]
}
