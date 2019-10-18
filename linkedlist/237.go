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
