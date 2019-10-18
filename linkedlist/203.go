/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    dummy := &ListNode{0, nil}
    dummy.Next = head
    head = dummy
    for dummy.Next != nil {
        if dummy.Next.Val == val {
            dummy.Next = dummy.Next.Next
        }else {
            dummy = dummy.Next
        }
    }
    return head.Next
}
