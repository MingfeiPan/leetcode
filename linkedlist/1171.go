/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 使用一个map 记录到每个node为止的sum
func removeZeroSumSublists(head *ListNode) *ListNode {
    var sumyet, tempsum int
    var temp *ListNode
    dummy := &ListNode{0, nil}
    dummy.Next = head
    record := make(map[int]*ListNode)
    // dummu刚好可以充当起始0点, 处理[1,-1] testcase
    record[0] = dummy
    for head != nil {
        sumyet += head.Val
        if pre, ok := record[sumyet]; !ok {
            record[sumyet] = head
        }else {
            // 发现匹配之后将前一个node.Next 指导现在的Next, 并且要把interval的sum记录都删掉
            temp = pre.Next
            tempsum = sumyet
            for temp != head {
                tempsum += temp.Val
                delete(record, tempsum)
                temp = temp.Next
            }
            pre.Next = head.Next
        }
        head = head.Next
    }
    return dummy.Next
    
}
