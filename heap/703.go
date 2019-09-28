type KthLargest struct {
	cursize  int
	capacity int
	list     []int    
}


func (h *KthLargest) LeftChild(pos int) int {
	if pos*2+1 < h.cursize {
		return pos*2 + 1
	} else {
		return -1
	}
}

func (h *KthLargest) Heapify(pos int) {
	if pos < h.cursize {
		curpos := pos
		lc := h.LeftChild(pos)
		rc := h.RightChild(pos)
		if lc > 0 && h.list[lc] < h.list[curpos] {
			curpos = lc
		}
		if rc > 0 && h.list[rc] < h.list[curpos] {
			curpos = rc
		}
		if curpos != pos {
			h.list[curpos], h.list[pos] = h.list[pos], h.list[curpos]
			h.Heapify(curpos)
		}
	}
}

func (h *KthLargest) RightChild(pos int) int {
	if pos*2+2 < h.cursize {
		return pos*2 + 2
	} else {
		return -1
	}
}

func (h *KthLargest) Insert(val int) {
	if h.cursize < h.capacity {
		h.list = append(h.list, val)
		pos := h.cursize
		h.cursize++
		for h.list[pos] < h.list[pos/2] {
			h.list[pos], h.list[pos/2] = h.list[pos/2], h.list[pos]
			pos = pos / 2
		}
	} else {
		if val < h.list[0] {
			return
		} else {
			h.list[0] = val
			h.Heapify(0)
		}
	}
}

func Constructor(k int, nums []int) KthLargest {
	var h KthLargest
	h.capacity = k  
    if k < len(nums){
        h.cursize = k
        h.list = nums[:k]
        // 初始化时做一次heapify很有必要
        for i := h.cursize/2; i > -1; i-- {
            h.Heapify(i)
        }
        for i := k; i < len(nums); i++ {
            h.Insert(nums[i])
        }        
    }else {
        h.cursize = 0
        for i := 0; i < len(nums); i++ {
            h.Insert(nums[i])
        }        
    }
    
    return h
}


func (this *KthLargest) Add(val int) int {
    this.Insert(val)
    return this.list[0]
}


/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
