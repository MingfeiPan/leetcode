/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }
    fast := head
    slow := head
    for slow != nil && slow.Next != nil {
        fast = fast.Next
        slow = slow.Next.Next
        if fast == slow {
            return true
        }
    }
    return false
}
