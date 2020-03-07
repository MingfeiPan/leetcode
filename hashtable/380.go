import "math/rand"
type RandomizedSet struct {
    m map[int]int
    l []int
}


/** Initialize your data structure here. */
func Constructor() RandomizedSet {
    rs := RandomizedSet{m: make(map[int]int), l: make([]int, 0)}
    return rs
}


/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
    if _, ok := this.m[val]; ok {
        return false
    }else {
        curindex := len(this.l)
        this.l = append(this.l, val)
        this.m[val] = curindex
    }
    return true
}


/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
    if index, ok := this.m[val]; !ok {
        return false
    }else {
        // 删除时应与末尾元素交换, 然后删掉末尾的
        lastVal := this.l[len(this.l)-1]
        this.m[lastVal] = index
        this.l[index], this.l[len(this.l)-1] = this.l[len(this.l)-1], this.l[index]
        delete(this.m, val)
        this.l = this.l[:len(this.l)-1]
    }
    return true
}


/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
    index := rand.Intn(len(this.l))
    return this.l[index]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
