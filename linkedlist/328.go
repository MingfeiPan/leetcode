/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    
    var (
        dummyOdd, dummyEven = head, head.Next
        flag = true
        cur *ListNode
    )
    for head != nil && head.Next != nil {
        //如果轮到判定odd node, 考察head.Next.Next如果为nil, 可以直接返回
        if head.Next.Next == nil && flag {
            break
        }
        cur = head.Next
        head.Next = head.Next.Next
        head = cur
        flag = ! flag
    }
    head.Next = dummyEven
    return dummyOdd
    
}
