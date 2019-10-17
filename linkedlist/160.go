/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    var dummy *ListNode
    var lena, lenb int 
    dummy = headA
    for dummy != nil {
        lena++
        dummy = dummy.Next
    }
    dummy = headB
    for dummy != nil {
        lenb++
        dummy = dummy.Next
    }
    if lena > lenb {
        for (lena - lenb) > 0 {
            headA = headA.Next
            lena--
        }
    }else {
        for (lenb - lena) > 0 {
            headB = headB.Next
            lenb--
        }        
    }
    for lena > 0 {
        if headA != nil && headA == headB {
            return headA
        }else {
            headA = headA.Next
            headB = headB.Next
        }
        lena--
    }
    return nil
}
