mport "sort"

func binarySearch(nums []int, num int) int {
    if len(nums) == 0 {
        return 0
    }
	start := 0
	end := len(nums) - 1
	var mid int
	for start < end {
		mid = (end-start)/2 + start
		if nums[mid] == num {
			return mid
		} else if nums[mid] < num {
			start = mid + 1
		} else {
			end = mid
		}
	}
	if nums[start] < num {
		return start + 1
	} else {
		return start
	}
}

func add_ret(ret []float64, windows []int, k int) []float64 {
	if k%2 == 0 {
		ret = append(ret, (float64(windows[k/2-1])+float64(windows[k/2]))/2)
	} else {
		ret = append(ret, float64(windows[k/2]))
	}
	return ret
}

func medianSlidingWindow(nums []int, k int) []float64 {
	var deleteindex, insertindex int
	// var deleteindex int
	ret := make([]float64, 0)
	rear := make([]int, 0)
	origin := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		origin = append(origin, nums[i])
	}
	windows := nums[:k]
	sort.Ints(windows)
	ret = add_ret(ret, windows, k)
	for i := 0; i < len(nums)-k; i++ {
		deleteindex = binarySearch(windows, origin[i])
		rear = windows[deleteindex+1:]
		windows = append(windows[:deleteindex], rear...)
		insertindex = binarySearch(windows, origin[i+k])
		rear = append([]int{}, windows[insertindex:]...)
		windows = append(append(windows[:insertindex], origin[i+k]), rear...)
		ret = add_ret(ret, windows, k)
	}
	return ret
}
