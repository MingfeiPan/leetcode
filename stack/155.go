type MinStack struct {
    main []int
    min []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    ms := MinStack{
        main: make([]int, 0),
        min: make([]int, 0),
    }
    return ms
}


func (this *MinStack) Push(x int)  {
    if len(this.min) == 0 {
        this.min = append(this.min, x)
    }else {
        if x <= this.GetMin() {
            this.min = append(this.min, x)
        }
    }
    this.main = append(this.main, x)
}


func (this *MinStack) Pop()  {
    index := len(this.min) - 1
    mainIndex := len(this.main) - 1
    if this.min[index] == this.main[mainIndex] {
        //remove last
        this.min = append(this.min[:index], this.min[index+1:]...)
    }
    this.main = append(this.main[:mainIndex], this.main[mainIndex+1:]...)
}


func (this *MinStack) Top() int {
    return this.main[len(this.main) - 1]
}


func (this *MinStack) GetMin() int {
    return this.min[(len(this.min) - 1)]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
