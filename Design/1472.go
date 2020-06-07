type BrowserHistory struct {
    Head *Node
    Tail *Node
    Cur *Node
}

type Node struct {
    Url string
    Pre *Node
    Next *Node
}

func Constructor(homepage string) BrowserHistory {
    head := &Node{"", nil, nil}
    tail := &Node{"", nil, nil}
    cur := &Node{homepage, nil, nil}
    head.Next = cur
    cur.Pre = head
    cur.Next = tail
    tail.Pre = cur
    return BrowserHistory{head, tail, cur}
}


func (this *BrowserHistory) Visit(url string)  {
    
    // visit 清理现在cur到tail的所有
    this.Cur.Next = this.Tail
    this.Tail.Pre = this.Cur
    
    //添加新的 cur
    cur := &Node{url, nil, nil}
    this.Cur.Next = cur
    cur.Pre = this.Cur
    cur.Next = this.Tail
    this.Tail.Pre = cur
    this.Cur = cur
}


func (this *BrowserHistory) Back(steps int) string {
    // 从cur回溯
    for steps > 0 {
        if this.Cur == this.Head {
            this.Cur = this.Head.Next
            return this.Cur.Url
        }
        this.Cur = this.Cur.Pre
        steps--
    }
    if this.Cur == this.Head {
        this.Cur = this.Head.Next
    }
    return this.Cur.Url
}


func (this *BrowserHistory) Forward(steps int) string {
    for steps > 0 {
        if this.Cur == this.Tail {
            this.Cur = this.Tail.Pre
            return this.Cur.Url
        }
        this.Cur = this.Cur.Next
        steps--
    }
    if this.Cur == this.Tail {
        this.Cur = this.Tail.Pre
    }
    return this.Cur.Url
}


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */
