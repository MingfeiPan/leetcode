type LRUCache struct {
    queue *Queue
    m map[int]*Node
}

type Node struct {
    key int
    val int
    pre *Node
    next *Node
}

type Queue struct {
    size int
    capacity int
    head *Node
    tail *Node
}


func Constructor(capacity int) LRUCache {
    head := &Node{-1, -1, nil, nil}
    tail := &Node{-1, -1, nil, nil}
    head.next = tail
    tail.pre = head
    queue := &Queue{0, capacity, head, tail}
    m := make(map[int]*Node)
    return LRUCache{queue, m}
}


func (this *LRUCache) Get(key int) int {
    if node, ok := this.m[key]; !ok {
        return -1
    }else {
        // found, update queue
        // remove from cur pos
        node.pre.next = node.next
        node.next.pre = node.pre
        // move to the head
        head := this.queue.head
        node.next = head.next
        head.next.pre = node
        head.next = node
        node.pre = head
        return node.val
    }
}


func (this *LRUCache) Put(key int, value int)  {
    if node, ok := this.m[key]; ok {
        // update
        this.m[key].val = value
        // remove from cur pos
        node.pre.next = node.next
        node.next.pre = node.pre
        // move to the head
        head := this.queue.head
        node.next = head.next
        head.next.pre = node
        head.next = node
        node.pre = head        
    }else {
        // insert
        if this.queue.size < this.queue.capacity {
            node := &Node{key, value, nil, nil}
            // move to the head
            head := this.queue.head
            node.next = head.next
            head.next.pre = node
            head.next = node
            node.pre = head  
            this.queue.size++
            this.m[key] = node
        }else {
            // remove the tail one
            tail := this.queue.tail.pre
            delete(this.m, tail.key)
            tail.pre.next = this.queue.tail
            this.queue.tail.pre = tail.pre
            
            node := &Node{key, value, nil, nil}
            // move to the head
            head := this.queue.head
            node.next = head.next
            head.next.pre = node
            head.next = node
            node.pre = head  
            this.queue.size++
            this.m[key] = node
            
        }
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
