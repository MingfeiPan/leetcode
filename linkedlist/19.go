/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    var pre *ListNode
    dummy := &ListNode{0, nil}
    dummy.Next = head
    pre = dummy
    head = dummy
    for n >= 0 {
        pre = pre.Next
        n--
    }
    for pre != nil {
        head = head.Next
        pre = pre.Next
    }

    head.Next = head.Next.Next
    return dummy.Next
}
