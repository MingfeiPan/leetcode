type StockSpanner struct {
    list []int
    ret []int
    index int
}


func Constructor() StockSpanner {
    ss := StockSpanner{
        list: make([]int, 0),
        ret: make([]int, 0),
        index: 0,
    }
    return ss
}


func (this *StockSpanner) Next(price int) int {

    this.list = append(this.list, price)
    init := 1
    for i := this.index-1; i >= 0; i-- {
        if price == this.list[i] {
            init = init + this.ret[i]
            break
        }else if this.list[i] > price {
            break
        }else {
            init++
        }
    }
    this.ret = append(this.ret, init)
    this.index++
    return init
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */



type Item struct {
    price int
    value int
}

type StockSpanner struct {
    list []*Item
}


func Constructor() StockSpanner {
    ss := StockSpanner{
        list: make([]*Item, 0),
    }
    return ss
}


func (this *StockSpanner) Next(price int) int {
    value := 1
    for len(this.list) > 0 && this.list[len(this.list)-1].price <= price {
        value += this.list[len(this.list)-1].value
        this.list = this.list[:(len(this.list)-1)]
    }
    this.list = append(this.list, &Item{price, value})
    return this.list[len(this.list)-1].value
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
