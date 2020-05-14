type MyCircularDeque struct {
	Size     int
	Capacity int
	Head     *Node
	Tail     *Node    
}

type Node struct {
	Val  int
	Pre  *Node
	Next *Node
}


/** Initialize your data structure here. Set the size of the deque to be k. */
func Constructor(k int) MyCircularDeque {
	head := &Node{0, nil, nil}
	tail := &Node{0, nil, nil}
	head.Next = tail
	tail.Pre = head
	return MyCircularDeque{0, k, head, tail}    
}


/** Adds an item at the front of Deque. Return true if the operation is successful. */
func (this *MyCircularDeque) InsertFront(value int) bool {
	if this.Capacity == this.Size {
		return false
	}
	node := &Node{value, nil, nil}
	node.Next = this.Head.Next
	this.Head.Next.Pre = node
	this.Head.Next = node
    node.Pre = this.Head
	this.Size++
	return true    
}


/** Adds an item at the rear of Deque. Return true if the operation is successful. */
func (this *MyCircularDeque) InsertLast(value int) bool {
	if this.Capacity == this.Size {
		return false
	}
	node := &Node{value, nil, nil}
	node.Pre = this.Tail.Pre
	this.Tail.Pre.Next = node
	this.Tail.Pre = node
    node.Next = this.Tail
	this.Size++
	return true    
}


/** Deletes an item from the front of Deque. Return true if the operation is successful. */
func (this *MyCircularDeque) DeleteFront() bool {
	if this.Size == 0 {
		return false
	}
	cur := this.Head.Next
	cur.Next.Pre = this.Head
	this.Head.Next = cur.Next
	this.Size--
	return true   
}


/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
func (this *MyCircularDeque) DeleteLast() bool {
	if this.Size == 0 {
		return false
	}
	cur := this.Tail.Pre
	cur.Pre.Next = this.Tail
	this.Tail.Pre = cur.Pre
	this.Size--
	return true    
}


/** Get the front item from the deque. */
func (this *MyCircularDeque) GetFront() int {
	if this.Size == 0 {
		return -1
	}
	return this.Head.Next.Val    
}


/** Get the last item from the deque. */
func (this *MyCircularDeque) GetRear() int {
	if this.Size == 0 {
		return -1
	}
	return this.Tail.Pre.Val    
}


/** Checks whether the circular deque is empty or not. */
func (this *MyCircularDeque) IsEmpty() bool {
    return this.Size == 0
}


/** Checks whether the circular deque is full or not. */
func (this *MyCircularDeque) IsFull() bool {
    return this.Size == this.Capacity
}


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */
