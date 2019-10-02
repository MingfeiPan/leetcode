func Sort(arr *[]int, left int, right int) int {
	length := right - left + 1
	var (
		i int
		j int
	)
	for i = 0; i < length; i++ {
		for j = i; j > 0; j-- {
			if (*arr)[j+left] < (*arr)[j+left-1] {
				(*arr)[j+left], (*arr)[j+left-1] = (*arr)[j+left-1], (*arr)[j+left]
			}
		}
	}
	return (right - left) / 2 + left
}

func partion(arr *[]int, left int, right int, pivot int) int {
	(*arr)[pivot], (*arr)[right] = (*arr)[right], (*arr)[pivot]
	index := left
	for i := left; i < right; i++ {
		if (*arr)[i] > (*arr)[right] {
			(*arr)[i], (*arr)[index] = (*arr)[index], (*arr)[i]
			index++
		}
	}
	(*arr)[index], (*arr)[right] = (*arr)[right], (*arr)[index]
	return index
}

func getPivot(arr *[]int, left int, right int) int {
	if right - left < 5 {
		return Sort(arr, left, right)
	}
	flag := left - 1
	var index int
	for i := left; i+4 <= right; i+=5 {
		index = Sort(arr, i, i+4)
		flag++
		(*arr)[flag], (*arr)[index] = (*arr)[index], (*arr)[flag]
	}
	return Bfprt(arr, left, flag, (flag - left + 1) / 2 + 1)
}

func Bfprt(arr *[]int, left int, right int, k int) int {
	pivot := getPivot(arr, left, right)
	index := partion(arr, left, right, pivot)
	ret := index - left + 1
	if ret == k {
		return index
	}else if ret > k {
		return Bfprt(arr, left, index-1, k)
	}else{
		return Bfprt(arr, index+1, right, k - ret)
	}
}

func findKthLargest(nums []int, k int) int {
    index := Bfprt(&nums, 0, len(nums)-1, k)
    return nums[index]
}
