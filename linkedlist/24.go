/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    var dummy, pre, cur, next *ListNode
    dummy = &ListNode{0, nil}
    dummy.Next = head
    pre = dummy
    for head != nil && head.Next != nil {
        cur = head
        next = head.Next
        cur.Next = head.Next.Next
        pre.Next = next
        next.Next = cur
        head = cur.Next
        pre = pre.Next.Next
    }
    return dummy.Next
}
