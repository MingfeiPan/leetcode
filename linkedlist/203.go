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

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    dummy := &ListNode{-1, nil}
    dummy.Next = head
    head = dummy
    for head != nil && head.Next != nil {
        if head.Next.Val == val {
            head.Next = head.Next.Next
        }else {
            head = head.Next    
        }
    }
    return dummy.Next
}
