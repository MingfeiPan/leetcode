/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    var fast, slow *ListNode
    fast = head
    slow = head
    for slow != nil && slow.Next != nil {
        fast = fast.Next
        slow = slow.Next.Next
    }
    return fast
}
