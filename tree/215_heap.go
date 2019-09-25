type heap struct {
	cursize  int
	capacity int
	list     []int
}

func (h *heap) LeftChild(pos int) int {
	if pos*2+1 < h.cursize {
		return pos*2 + 1
	} else {
		return -1
	}
}

func (h *heap) RightChild(pos int) int {
	if pos*2+2 < h.cursize {
		return pos*2 + 2
	} else {
		return -1
	}
}

func (h *heap) Heapify(pos int) {
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

func Init(capacity int) *heap {
	var h heap
	h.capacity = capacity
	return &h
}

func (h *heap) Insert(val int) {
	if h.cursize < h.capacity {
		h.list = append(h.list, val)
		pos := h.cursize
		h.cursize++
		for h.list[pos] < h.list[pos/2] {
			h.list[pos], h.list[pos/2] = h.list[pos/2], h.list[pos]
			pos = pos / 2
		}
	} else {
		if val <= h.list[0] {
			return
		} else {
			h.list[0] = val
			h.Heapify(0)
		}
	}
}

func findKthLargest(nums []int, k int) int {
    h := Init(k)
    for _, v := range nums {
        h.Insert(v)
    }
    return h.list[0]
}
