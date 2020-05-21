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

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil || head.Next.Next == nil {
        return head
    }
    
    dummy := &ListNode{-1, head}
    dummy2 := &ListNode{-1, head.Next}
    for head != nil && head.Next != nil && head.Next.Next != nil {
        cur := head.Next
        next := head.Next.Next
        head.Next = next
        cur.Next = next.Next
        head = head.Next
    }
    head.Next = dummy2.Next
    return dummy.Next
}
