/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    l := make([]*TreeNode, 0)
    for {
        for root != nil {
            l = append(l, root)
            root = root.Left
        }
        if k == 1 {
            return l[len(l) - 1].Val
        }
        root = l[len(l) - 1]
        k--
        l = l[:len(l) - 1]
        root = root.Right
    }
    
}
