/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    // fast slow node will meet before cycle node
    if head == nil {
        return nil
    }
    fast := head
    slow := head
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
        if fast == slow {
            break
        }
    }
    if fast == nil || fast.Next == nil {
        return nil
    }
    fast = head
    for fast != nil {
        if fast == slow {
            break
        }
        fast = fast.Next
        slow = slow.Next
    }
    return fast
}
