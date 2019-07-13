/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
    if root == nil {
        return true
    }
    var (
        l  []*TreeNode
        num  int
    )
    l = append(l, root)
    num = root.Val
    
    for len(l) > 0 {
        root = l[len(l) - 1]
        l = l[:len(l) - 1]
        if root.Val != num {
            return false
        }
        if root.Left != nil {
            l = append(l, root.Left)
        }
        if root.Right != nil {
            l = append(l, root.Right)
        }
    }
    return true
    
    
}
