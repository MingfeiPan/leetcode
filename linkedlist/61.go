/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil {
        return nil
    }
    var slow, fast *ListNode
    var length int
    slow = head
    fast = head
    for i := k; i > 0; {
        length++
        if fast == nil && i != 0 {
            fast = head
            // add length to remove extra movements for fast node
            if i > length {
                i = i % length + 1
            }
            continue
        }
        i--
        fast = fast.Next
    }
    for fast != nil && fast.Next != nil {
        fast = fast.Next
        slow = slow.Next
    }

    if fast == nil {
        return head
    }
    fast.Next = head
    head = slow.Next
    slow.Next = nil
    return head
    
}
