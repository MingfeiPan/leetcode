/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
    var length, base, extra int 
    var dummy, head *ListNode
    dummy = root
    for dummy != nil {
        length++ 
        dummy = dummy.Next
    }
    base = length / k
    extra = length % k
    ret := make([]*ListNode, 0)
    for k > 0 {
        // find the proper size of each linkedlist
        index := base
        if extra > 0 {
            index++
            extra--
        }
        head = root
        for index > 1 {
            root = root.Next
            index--
        }
        if root == nil {
            ret = append(ret, nil)
        }else {
            ret = append(ret, head)
            dummy = root.Next
            root.Next = nil
            root = dummy            
        }
        k--
    }
    return ret
}
