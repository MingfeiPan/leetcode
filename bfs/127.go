type Item struct {
    word string
    step int
}
func ladderLength(beginWord string, endWord string, wordList []string) int {
    wordMap := make(map[string]struct{})
    queue := make([]Item, 0)
    queue = append(queue, Item{beginWord, 1})
    for len(queue) > 0 {
        item := queue[0]
        queue = queue[1:]
        fitList := findFit(item.word, wordList, wordMap)
        for _, s := range fitList {
            if s == endWord {
                return item.step + 1
            }
            queue = append(queue, Item{s, item.step+1})
        }
    }
    return 0
}

func findFit(source string, targetList []string, targetMap map[string]struct{}) []string {
    ret := make([]string, 0)
    for _, s := range targetList {
        if _, ok := targetMap[s]; !ok && compareStr(source, s) {
            ret = append(ret, s)
            targetMap[s] = struct{}{}
        }
    }
    return ret
}

func compareStr(source string, target string) bool {
    var flag bool
    for i := 0; i < len(source); i++ {
        if source[i] != target[i] {
            if flag {
                return false
            }else {
                flag = true
            }
        }
    } 
    return true
} 
