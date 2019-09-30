type Element struct {
	Val  int
	Freq int
}

type Heap struct {
	El       []*Element
	Size     int
	Capacity int
}

func (h *Heap) LeftChild(pos int) int {
	if pos*2+1 < h.Size {
		return pos*2 + 1
	} else {
		return -1
	}
}

func (h *Heap) RightChild(pos int) int {
	if pos*2+2 < h.Size {
		return pos*2 + 2
	} else {
		return -1
	}
}

func Constructor(capacity int) *Heap {
	var h Heap
	h.Capacity = capacity
	return &h
}

func BuildMap(nums []int) map[int]int {
	m := make(map[int]int, 0)
	for _, val := range nums {
		if freq, ok := m[val]; !ok {
			m[val] = 1
		} else {
			m[val] = freq + 1
		}
	}
	return m
}

func (h *Heap) Insert(val int, freq int) {
	if h.Size < h.Capacity{
		ele := Element{Val: val, Freq: freq}
		h.El = append(h.El, &ele)
		curpos := h.Size
		h.Size++
		for h.El[curpos].Freq < h.El[(curpos-1)/2].Freq {
			h.El[curpos], h.El[(curpos-1)/2] = h.El[(curpos-1)/2], h.El[curpos]
			curpos = (curpos-1) / 2
		}
	} else {
		if freq > h.El[0].Freq {
			h.El[0].Freq = freq
			h.El[0].Val = val
			h.Heapify(0)
		}
	}
}

func (h *Heap) Heapify(pos int) {
	if pos < h.Size {
		curpos := pos
		lc := h.LeftChild(pos)
		rc := h.RightChild(pos)
		if lc > 0 && h.El[lc].Freq < h.El[curpos].Freq {
			curpos = lc
		}
		if rc > 0 && h.El[rc].Freq < h.El[curpos].Freq {
			curpos = rc
		}
		if curpos != pos {
			h.El[curpos], h.El[pos] = h.El[pos], h.El[curpos]
			h.Heapify(curpos)
		}
	}
}

func (h *Heap) getVals() []int {
	ret := make([]int, 0)
	for _, v := range h.El[:h.Capacity] {
		ret = append(ret, v.Val)
	}
	return ret
}

func topKFrequent(nums []int, k int) []int {
    numsMap := BuildMap(nums)
    maxHeap := Constructor(k)
    for i, v := range numsMap {
        maxHeap.Insert(i, v)
    }
    ret := maxHeap.getVals()
    return ret
}
