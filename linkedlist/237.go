/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
    // swap with next
    node.Val = node.Next.Val
    node.Next = node.Next.Next
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
    for node != nil && node.Next != nil {
        if node.Next.Next == nil {
            node.Val = node.Next.Val
            node.Next = nil
            break
        }
        node.Val = node.Next.Val
        node = node.Next
        
    }
}
