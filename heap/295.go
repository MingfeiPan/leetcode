type MedianFinder struct {
	Size   int
	lefth  *Heap
	righth *Heap
}

type Heap struct {
	Size int
	list []int
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

func (h *Heap) Heapify(pos int, flag string) {
	if pos < h.Size {
		curpos := pos
		lc := h.LeftChild(pos)
		rc := h.RightChild(pos)
		if flag == "maxheap" {
			if lc > 0 && h.list[lc] > h.list[curpos] {
				curpos = lc
			}
			if rc > 0 && h.list[rc] > h.list[curpos] {
				curpos = rc
			}
		} else {
			// minheap
			if lc > 0 && h.list[lc] < h.list[curpos] {
				curpos = lc
			}
			if rc > 0 && h.list[rc] < h.list[curpos] {
				curpos = rc
			}
		}
		if curpos != pos {
			h.list[curpos], h.list[pos] = h.list[pos], h.list[curpos]
			h.Heapify(curpos, flag)
		}
	}
}

func Init() *Heap {
	var h Heap
    h.list = make([]int, 0)
    h.Size = 0
	return &h
}

func (h *Heap) Insert(val int, flag string) {
	h.list = append(h.list, val)
	cursize := h.Size
	h.Size++
	if flag == "maxheap" {
        for h.list[cursize] > h.list[(cursize-1)/2] {
            h.list[cursize], h.list[(cursize-1)/2] = h.list[(cursize-1)/2], h.list[cursize]
            cursize = (cursize-1) / 2
		}
	} else {       
        for h.list[cursize] < h.list[(cursize-1)/2] {
            h.list[cursize], h.list[(cursize-1)/2] = h.list[(cursize-1)/2], h.list[cursize]
            cursize = (cursize-1) / 2
		}
	}
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	var mf MedianFinder
	mf.Size = 0
	mf.lefth = Init()
	mf.righth = Init()
    return mf
}


func (this *MedianFinder) AddNum(num int)  {
    if this.Size == 0 {
        this.lefth.Insert(num, "maxheap")
        this.Size++
        return
    }
    if this.lefth.Size >= this.righth.Size {
        if num < this.lefth.list[0] {
            this.righth.Insert(this.lefth.list[0], "minheap")
            this.lefth.list[0] = num
            this.lefth.Heapify(0, "maxheap")
        }else {
            this.righth.Insert(num, "minheap")
        }
    }else {
        if num > this.righth.list[0] {
            this.lefth.Insert(this.righth.list[0], "maxheap")
            this.righth.list[0] = num
            this.righth.Heapify(0, "minheap")
        }else{
            this.lefth.Insert(num, "maxheap")    
        }
    }
    this.Size++
}


func (this *MedianFinder) FindMedian() float64 {

    if this.Size % 2 == 0 {
        return (float64(this.lefth.list[0]) + float64(this.righth.list[0])) / 2
    }else{
        if this.lefth.Size > this.righth.Size {
            return float64(this.lefth.list[0])    
        }else {
            return float64(this.righth.list[0])
        }
    }
}


/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
