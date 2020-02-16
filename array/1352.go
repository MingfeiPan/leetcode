type ProductOfNumbers struct {
    list []int
}


func Constructor() ProductOfNumbers {
    p := ProductOfNumbers{list:make([]int, 0)}
    return p
}


func (this *ProductOfNumbers) Add(num int)  {
    this.list = append(this.list, num)
}


func (this *ProductOfNumbers) GetProduct(k int) int {
    index := len(this.list) - 1
    product := 1
    for k > 0 {
        if this.list[index] == 0 {
            return 0
        }
        product *= this.list[index]
        index--
        k--
    }
    return product
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */
