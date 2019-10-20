/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    smallpre := &ListNode{0, nil}
    largepre := &ListNode{0, nil}
    
    smallhead := smallpre
    largehead := largepre
    
    for head != nil {
        if head.Val < x {
            smallhead.Next = head
            smallhead = smallhead.Next
        }else {
            largehead.Next = head
            largehead = largehead.Next
        }
        head = head.Next
    }
    // remember for the end
    largehead.Next = nil
    smallhead.Next = largepre.Next
    return smallpre.Next
}
