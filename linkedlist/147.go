/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertionSortList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }   
    var cur, dummy, temp *ListNode
    
    cur = head.Next //遍历的起点
    head.Next = nil //排序后链表的头
    
    for cur != nil {
        dummy = head //重制dummy到头节点
        if cur.Val <= dummy.Val {
            //移动cur
            temp = cur
            cur = cur.Next
            //插入到head之前
            temp.Next = head
            head = temp
        }else {
            //找到cur在结果集里的位置
            for dummy.Next != nil && cur.Val > dummy.Next.Val {
                dummy = dummy.Next
            }
            //如果是cur是已知最大的, 放到最后
            if dummy.Next == nil {
                temp = cur
                cur = cur.Next
                temp.Next = nil
                dummy.Next = temp
            }else {
                //放在dummy后面
                temp = cur
                cur = cur.Next
                temp.Next = dummy.Next
                dummy.Next = temp
            }
        }
    }
    return head
}
