type MapSum struct {
    next map[rune]*MapSum
    sum int
    isWord bool
}


/** Initialize your data structure here. */
func Constructor() MapSum {
    m := MapSum{
        next: make(map[rune]*MapSum),
        sum: 0,
        isWord: false,
    }
    return m
}


func (this *MapSum) Insert(key string, val int)  {
    for _, c := range key {
        if _, ok := this.next[c]; !ok {
            this.next[c] = &MapSum{next: make(map[rune]*MapSum), sum: 0, isWord: false}
        }
        this = this.next[c]
    }
    this.sum = val
    this.isWord = true
}


func (this *MapSum) Sum(prefix string) int {
    for _, c := range prefix {
        if _, ok := this.next[c]; !ok {
            return 0
        }
        this = this.next[c]
    }
    if this == nil {
        return 0
    }
    l := make([]*MapSum, 0)
    var ret int
    l = append(l, this)
    for len(l) > 0 {
        this = l[len(l)-1]
        l = l[:len(l)-1]
        if this.isWord {
            ret += this.sum
        }
        for i, _ := range this.next {
            
            l = append(l, this.next[i])
        }
    }
    return ret
}


/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
