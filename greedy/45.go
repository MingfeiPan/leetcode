import "math"

func jump(nums []int) int {
	list := make([]int, len(nums))
	for i := 1; i < len(nums); i++ {
		list[i] = math.MaxInt32
	}
	for i := 0; i < len(nums)-1; i++ {
		for j := 1; j <= nums[i]; j++ {
			if i+j < len(nums) && list[i]+1 < list[i+j] {
				list[i+j] = list[i] + 1
			}
		}
	}
	return list[len(nums)-1]
}
