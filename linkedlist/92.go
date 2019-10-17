/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    var pre, next *ListNode
    dummy := &ListNode{0, nil}
    dummy.Next = head
    pre = dummy
    for m > 1 {
        head = head.Next
        pre = pre.Next
        m--
        n--
    }
    for n - m > 0 {
        next = head.Next
        head.Next = next.Next
        next.Next = pre.Next
        pre.Next = next
        n--
    }
    return dummy.Next
    
}
