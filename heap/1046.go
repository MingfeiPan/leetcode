type Heap struct{
    list []int
    size int
}

func (h *Heap) LeftChild(pos int) int{
    if pos * 2 + 1 < h.size {
        return pos * 2 + 1
    }else {
        return -1
    }
}

func (h *Heap) RightChild(pos int) int{
    if pos * 2 + 2 < h.size {
        return pos * 2 + 2
    }else {
        return -1
    }
}

func (h *Heap) Heapify(pos int) {
    if pos < h.size {
        curpos := pos
        lc := h.LeftChild(pos)
        rc := h.RightChild(pos)
        if lc > 0 && h.list[lc] > h.list[curpos] {
            curpos = lc
        }
        if rc > 0 && h.list[rc] > h.list[curpos] {
            curpos = rc
        }
        if curpos != pos {
            h.list[pos], h.list[curpos] = h.list[curpos], h.list[pos]
            h.Heapify(curpos)
        }
    }
}

func Init(nums []int) *Heap {
    var h Heap
    h.list = nums
    h.size = len(nums)
    for i := h.size / 2; i >=0; i-- {
        h.Heapify(i)
    }
    return &h
}

func (h *Heap) GetTop() int {
    temp := h.list[0]
    h.list[0], h.list[h.size-1] = h.list[h.size-1], h.list[0]
    // h.list = h.list[:h.size]
    h.size--
    h.Heapify(0)
    return temp
}

func (h *Heap) Insert(num int) {
    h.list[h.size] = num
    cursize := h.size
    h.size++
    for h.list[cursize] > h.list[(cursize-1) / 2] {
        h.list[cursize], h.list[(cursize-1) / 2] = h.list[(cursize-1) / 2], h.list[cursize]
        cursize = (cursize-1) / 2
    }
}

func lastStoneWeight(stones []int) int {
    h := Init(stones)
    var s1, s2 int
    for h.size > 1 {
        s1 = h.GetTop()
        s2 = h.GetTop()
        if s1 < s2 {
            h.Insert(s2-s1)
        }else if s1 > s2 {
            h.Insert(s1-s2)
        }
    }
    if h.size == 0 {
        return 0
    }
    return h.list[0]
}
