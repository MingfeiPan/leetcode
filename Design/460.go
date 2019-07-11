package main

import (
	"fmt"
	"math"
)

type LFUCache struct {
	size     int
	Capacity int
	MainMap  map[int]*Data
	CountMap map[int]*[]int
}

type Data struct {
	value int
	count int
}

func Constructor(capacity int) LFUCache {
	Lc := LFUCache{
		size:     0,
		Capacity: capacity,
		MainMap:  make(map[int]*Data),
		CountMap: make(map[int]*[]int),
	}
	return Lc
}

func (this *LFUCache) Get(key int) int {
	var (
		data    *Data
		counter *[]int
		ok      bool
	)
	//if not exists
	if data, ok = this.MainMap[key]; !ok {
		return -1
	}

	if counter, ok = this.CountMap[data.count]; !ok {
		panic("error in CountMap")
	}
	//remove old
	for i, curKey := range *counter {
		if curKey == key {
			if len(*counter) == 1 {
				delete(this.CountMap, data.count)
			} else {
				*counter = append((*counter)[:i], (*counter)[i+1:]...)
			}
			break
		}
	}
	//add new
	if _, ok := this.CountMap[data.count+1]; !ok {
		this.CountMap[data.count+1] = &[]int{key}
	} else {
		*this.CountMap[data.count+1] = append(*this.CountMap[data.count+1], key)
	}
	this.MainMap[key].count++
	return data.value
}

func (this *LFUCache) Put(key int, value int) {
	var (
		data      *Data
		counter   *[]int
		cur_index int
		ok        bool
	)
	if this.Capacity == 0 {
		return
	}

	//if exists
	if data, ok = this.MainMap[key]; ok {
		//remove old
		if counter, ok = this.CountMap[data.count]; !ok {
			panic("error in CountMap")
		}
		for i, curKey := range *counter {
			if curKey == key {
				if len(*counter) == 1 {
					delete(this.CountMap, data.count)
				} else {
					*counter = append((*counter)[:i], (*counter)[i+1:]...)
				}
				break
			}
		}
		//add new
		if _, ok = this.CountMap[data.count+1]; !ok {
			this.CountMap[data.count+1] = &[]int{key}
		} else {
			*this.CountMap[data.count+1] = append(*this.CountMap[data.count+1], key)
		}
		//replace value
		this.MainMap[key].value = value
		this.MainMap[key].count = data.count + 1
	} else {
		if this.size < this.Capacity {
			newData := Data{
				value: value,
				count: 1,
			}
			this.MainMap[key] = &newData
			if _, ok := this.CountMap[1]; !ok {
				this.CountMap[1] = &[]int{key}
			} else {
				*this.CountMap[1] = append(*this.CountMap[1], key)
			}
			this.size++
		} else {
			//make room
			index := math.MaxInt32
			for cur_index, _ = range this.CountMap {
				if cur_index < index {
					index = cur_index
				}
			}
			if len(*this.CountMap[index]) == 1 {
				cur_key := (*this.CountMap[index])[0]
				//remove
				delete(this.CountMap, index)
				delete(this.MainMap, cur_key)
			} else {
				cur_key := (*this.CountMap[index])[0]
				(*this.CountMap[index]) = append((*this.CountMap[index])[:0], (*this.CountMap[index])[1:]...)
				delete(this.MainMap, cur_key)
			}
			newData := Data{
				value: value,
				count: 1,
			}
			this.MainMap[key] = &newData
			if _, ok := this.CountMap[1]; !ok {
				this.CountMap[1] = &[]int{key}
			} else {
				*this.CountMap[1] = append(*this.CountMap[1], key)
			}
		}
	}
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

