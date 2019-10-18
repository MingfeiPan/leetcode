/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var flag bool
    dummy := &ListNode{0, nil}
    dummy.Next = l1
    pre := dummy
    for l1 != nil && l2 != nil {
        if flag {
            if l1.Val + l2.Val + 1 > 9 {
                l1.Val = l1.Val + l2.Val + 1 - 10
                flag = true
            }else {
                l1.Val = l1.Val + l2.Val + 1
                flag = false
            }
        }else {
            if l1.Val + l2.Val > 9 {
                l1.Val = l1.Val + l2.Val - 10
                flag = true
            }else {
                l1.Val = l1.Val + l2.Val
                flag = false
            }
        }
        pre = pre.Next
        l1 = l1.Next
        l2 = l2.Next
    }
    if l1 == nil && l2 == nil && flag {
        pre.Next = &ListNode{1, nil}
        return dummy.Next
    }
    if l2 != nil {
        pre.Next = l2
        l1 = pre.Next
    }
    for l1 != nil {
        if flag {
            if l1.Val + 1 > 9 {
                if l1.Next == nil {
                    l1.Val = 0
                    l1.Next = &ListNode{1, nil}
                    return dummy.Next
                }else {
                    l1.Val = 0
                    flag = true                    
                }
            }else {
                l1.Val++
                flag = false
            }
        }
        l1 = l1.Next
    }
    return dummy.Next
}
