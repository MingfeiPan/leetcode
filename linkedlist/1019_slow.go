/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nextLargerNodes(head *ListNode) []int {
    var dummy *ListNode
    var foundflag bool
    ret := make([]int, 0)
    for head != nil && head.Next != nil {
        foundflag = false
        dummy = head.Next
        for dummy != nil {
            if dummy.Val > head.Val {
                ret = append(ret, dummy.Val)
                foundflag = true
                break
            }
            dummy = dummy.Next
        }
        if !foundflag{
            ret = append(ret, 0)
        }
        head = head.Next
    }
    ret = append(ret, 0)
    return ret
}
