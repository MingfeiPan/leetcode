type Item struct {
	val   int
	index int
}

type Heap struct {
	size int
	list []*Item
}

func (h *Heap) LeftChild(pos int) int {
	if pos*2+1 < h.size {
		return pos*2 + 1
	} else {
		return -1
	}
}

func (h *Heap) RightChild(pos int) int {
	if pos*2+2 < h.size {
		return pos*2 + 2
	} else {
		return -1
	}
}

func (h *Heap) Heapify(pos int) {
	if pos < h.size {
		curpos := pos
		lc := h.LeftChild(pos)
		rc := h.RightChild(pos)
		if lc > 0 && h.list[lc].val > h.list[curpos].val {
			curpos = lc
		}
		if rc > 0 && h.list[rc].val > h.list[curpos].val {
			curpos = rc
		}

		if curpos != pos {
			h.list[pos], h.list[curpos] = h.list[curpos], h.list[pos]
			h.Heapify(curpos)
		}
	}
}

func (h *Heap) Insert(val int, index int) {
	item := Item{val: val, index: index}
	h.list = append(h.list, &item)
	cursize := h.size
	h.size++
	for h.list[cursize].val > h.list[(cursize-1)/2].val {
		h.list[cursize], h.list[(cursize-1)/2] = h.list[(cursize-1)/2], h.list[cursize]
		cursize = (cursize - 1) / 2
	}
}

func Init() *Heap {
	h := Heap{
		size: 0,
		list: make([]*Item, 0),
	}
	return &h
}

func (h *Heap) RemoveTop() {
	h.list[0] = h.list[h.size-1]
    // 注意这不是一个定长的heap
    h.list = h.list[:h.size-1]
	h.size--
	h.Heapify(0)
}

func maxSlidingWindow(nums []int, k int) []int {
	if len(nums) == 0 {
		return nil
	}
	ret := make([]int, 0)
	h := Init()
	for i := 0; i < k; i++ {
		h.Insert(nums[i], i)
	}
	ret = append(ret, h.list[0].val)
	for i := 0; i < len(nums)-k; i++ {
		if nums[i] == h.list[0].val {
			// 此时要删除的就是 top 直接替换
			h.list[0].val = nums[i+k]
			h.list[0].index = i + k
			h.Heapify(0)
		} else {
			// 不等于时, 不用删除只添加
			h.Insert(nums[i+k], i+k)
		}
		// 此时查看top, 在index范围内则添加, 不在则remove top
		for h.list[0].index <= i {
			h.RemoveTop()
		}
		ret = append(ret, h.list[0].val)
	}
	return ret
}
