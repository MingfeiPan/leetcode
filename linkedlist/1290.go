/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    nums := make([]int, 0)
    for head != nil {
        nums = append(nums, head.Val)
        head = head.Next
    }
    var ret int
    for i := len(nums)-1; i >=0; i-- {
        ret += int(math.Exp2(float64(len(nums)-1-i)))*nums[i]
    }
    return ret
}
