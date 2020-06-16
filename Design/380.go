mport "math/rand"

type RandomizedSet struct {
    m map[int]int
    l []int
}


/** Initialize your data structure here. */
func Constructor() RandomizedSet {
    return RandomizedSet{make(map[int]int), make([]int, 0)}
}


/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
    if _, ok := this.m[val]; ok {
        return false
    }else {
        curIndex := len(this.l)
        this.l = append(this.l, val)
        this.m[val] = curIndex
        return true
    }
}


/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
    if index, ok := this.m[val]; !ok {
        return false
    }else {
        // swap with last one
        this.m[this.l[len(this.l)-1]] = index
        this.l[index], this.l[len(this.l)-1] = this.l[len(this.l)-1], this.l[index]
        this.l = this.l[:len(this.l)-1]
        delete(this.m, val)
        return true
    }
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
