/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func twowayMerge(l1 *ListNode, l2 *ListNode) *ListNode {
    var dummy, head *ListNode
    dummy = &ListNode{0, nil}
    dummy.Next = l1
    head = dummy
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            head.Next = l1
            l1 = l1.Next
        }else {
            head.Next = l2
            l2 = l2.Next
        }
        head = head.Next
    }
    if l1 != nil {
        head.Next = l1 
    }else {
        head.Next = l2
    }
    return dummy.Next
}
func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 {
        return nil
    }
    var curlen int
    for len(lists) >= 2 {
        curlen = len(lists)
        for i := 0; i < curlen / 2; i++ {
            lists[i] = twowayMerge(lists[i], lists[curlen-1-i])
        }
        if curlen % 2 == 0{
            lists = lists[:curlen / 2]    
        }else {
            lists = lists[:curlen / 2 + 1]
        }
    }
    return lists[0]
}
