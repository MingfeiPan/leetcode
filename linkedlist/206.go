/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    dummy := &ListNode{0, nil}
    dummy.Next = head
    var pre, next *ListNode
    pre = dummy
    
    for head != nil && head.Next != nil {
        next = head.Next
        head.Next = next.Next
        next.Next = pre.Next
        pre.Next = next
    }
    return dummy.Next
}
