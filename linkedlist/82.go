/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    dummy := &ListNode{math.MinInt32, nil}
    dummy.Next = head
    var flag bool
    var pre *ListNode
    pre = dummy
    for head != nil && head.Next != nil {
        if head.Val != head.Next.Val {
            if flag {
                pre.Next = head.Next
                flag = false
            }else {
                pre = pre.Next
            }
            head = head.Next
        }else {
            flag = true
            head = head.Next
        }
    }
    if flag {
        pre.Next = head.Next
    }
    return dummy.Next
}
