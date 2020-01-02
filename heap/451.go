type Item struct {
	freq int
	ele  byte
}

type Heap struct {
	list []*Item
	size int
}

func (h *Heap) leftChild(pos int) int {
	if pos*2+1 < h.size {
		return pos*2 + 1
	} else {
		return -1
	}
}

func (h *Heap) rightChild(pos int) int {
	if pos*2+2 < h.size {
		return pos*2 + 2
	} else {
		return -1
	}
}

func (h *Heap) Heapify(pos int) {
	if pos < h.size {
		curpos := pos
		lc := h.leftChild(curpos)
		rc := h.rightChild(curpos)
		if lc > 0 && h.list[lc].freq > h.list[curpos].freq {
			curpos = lc
		}
		if rc > 0 && h.list[rc].freq > h.list[curpos].freq {
			curpos = rc
		}
		if curpos != pos {
			h.list[pos], h.list[curpos] = h.list[curpos], h.list[pos]
			h.Heapify(curpos)
		}
	}
}

func (h *Heap) FirstSort() {
	for i := h.size / 2; i >= 0; i-- {
		h.Heapify(i)
	}
}

func (h *Heap) popTop() *Item {
	if h.size > 0 {
		item := h.list[0]
		h.list[0] = h.list[h.size-1]
		h.size--
		h.Heapify(0)
		return item
	}
	return nil
}

func frequencySort(s string) string {
	wordmap := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		if _, ok := wordmap[s[i]]; !ok {
			wordmap[s[i]] = 1
		} else {
			wordmap[s[i]]++
		}
	}
	h := Heap{list: make([]*Item, 0), size: 0}
	for ele, freq := range wordmap {
		item := Item{freq, ele}
		h.list = append(h.list, &item)
		h.size++
	}
	h.FirstSort()
    var ret string
    for h.size > 0 {
        item := h.popTop()
        count := item.freq
        for count > 0 {
            ret += string(item.ele)
            count--
        }
    }
    return ret
}
