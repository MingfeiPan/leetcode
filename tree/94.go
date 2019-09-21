/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    s := make([]*TreeNode, 0)
    l := make([]int, 0)
    for {
        for root != nil {
            s = append(s, root)
            root = root.Left
        }
        if len(s) == 0 {
            break
        }
        root = s[len(s)-1]
        s = s[:len(s)-1]
        l = append(l, root.Val)
        root = root.Right
    }
    return l
}
