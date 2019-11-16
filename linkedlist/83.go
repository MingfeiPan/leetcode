/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return head
    }
    dummy := &ListNode{0, nil}
    dummy.Next = head
    var pre *ListNode
    pre = dummy
    for head != nil && head.Next != nil {
        if head.Val == head.Next.Val {
            pre.Next = head.Next
        }else {
            pre = pre.Next
        }
        head = head.Next
    }
    return dummy.Next
}
