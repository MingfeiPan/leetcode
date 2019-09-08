/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    buf := make([]*TreeNode, 0)
    ret := make([]int, 0)
    buf = append(buf, root)
    for len(buf) > 0 {
        root = buf[len(buf)-1]
        buf = buf[:len(buf)-1]
        ret = append(ret, root.Val)
        if root.Right != nil {
            buf = append(buf, root.Right)
        }
        if root.Left != nil {
            buf = append(buf, root.Left)
        }
    }
    return ret
}
