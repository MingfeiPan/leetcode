/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    cur := findMid(head)
    t := &TreeNode{cur.Val, nil, nil}
    if cur == head {
        return t
    }
    t.Left = sortedListToBST(head)
    t.Right = sortedListToBST(cur.Next)
    return t
    
}

func findMid(head *ListNode) *ListNode {
    var dummy *ListNode
    fast := head
    slow := head
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        dummy = slow
        slow = slow.Next
    }
    if dummy != nil {
        dummy.Next = nil
    }
    return slow
}
