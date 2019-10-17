/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    var index, length int
    dummy := head
    for dummy != nil {
        dummy = dummy.Next
        length++
    }

    l := make([]int, length/2)
    
    for index < length / 2 {
        l = append(l, head.Val)
        head = head.Next
        index++
    }
    if length % 2 == 1 {
        head = head.Next
        index++
    }
    for index < length {
        if head.Val != l[len(l)-1] {
            return false
        }
        index++
        head = head.Next
        l = l[:len(l)-1]
    }
    return true
}
