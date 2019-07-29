import (
    "strings"
)
type MapSum struct {
    MainMap map[string]int
}


/** Initialize your data structure here. */
func Constructor() MapSum {
    Ms := MapSum{
        MainMap: make(map[string]int),
    }
    return Ms
}


func (this *MapSum) Insert(key string, val int)  {
    this.MainMap[key] = val
}


func (this *MapSum) Sum(prefix string) int {
    var ret int
    for key, value := range this.MainMap {
        if strings.HasPrefix(key, prefix) {
            ret += value
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
