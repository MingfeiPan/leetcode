type LRUCache struct {
	m        map[int]*Node
	size     int
	capacity int
	head     *Node
	tail     *Node
}

type Node struct {
	key int
	val  int
	pre  *Node
	next *Node
}

func Constructor(capacity int) LRUCache {
	mainmap := LRUCache{
		m:        make(map[int]*Node),
		size:     0,
		capacity: capacity,
        head:     &Node{-1, -1, nil, nil},
        tail:     &Node{-1, -1, nil, nil},
	}
    mainmap.head.next = mainmap.tail
    mainmap.tail.pre = mainmap.head
	return mainmap
}

func (this *LRUCache) Get(key int) int {
	if node, ok := this.m[key]; !ok {
		return -1
	} else {
		node.pre.next = node.next
		node.next.pre = node.pre
        temp := this.tail.pre
        temp.next = node
        node.pre = temp
        node.next = this.tail
		this.tail.pre = node
		return node.val
	}
}

func (this *LRUCache) Put(key int, value int) {
    // fmt.Println(this.m)
	if _, ok := this.m[key]; !ok {
		if this.size < this.capacity {
            newnode := &Node{key, value, nil, nil}
            this.m[key] = newnode
            this.size++
            temp := this.tail.pre
            temp.next = newnode
            newnode.pre = temp
            newnode.next = this.tail
            this.tail.pre = newnode
		} else {
			newnode := &Node{key, value, nil, nil}

			//move head
			delete(this.m, this.head.next.key)
			temp := this.head.next.next
			temp.pre = this.head
			this.head.next = temp
			//add tail
			this.m[key] = newnode
			temp = this.tail.pre
			temp.next = newnode
			newnode.pre = temp
			newnode.next = this.tail
			this.tail.pre = newnode
		}
	} else {
		// when put is success, update
		this.m[key].val = value
        node := this.m[key]
		node.pre.next = node.next
		node.next.pre = node.pre
        temp := this.tail.pre
        temp.next = node
        node.pre = temp
        node.next = this.tail
		this.tail.pre = node		

	}
    // fmt.Println(this.m)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

