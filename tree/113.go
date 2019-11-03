/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, sum int) [][]int {
    ret := make([][]int, 0)
    recur(&ret, sum, []int{}, root)
    return ret
    
}
func recur(ret *[][]int, left int, cur []int, root *TreeNode) {
    if root == nil {
        return
    }
    if root.Left == nil && root.Right == nil && root.Val == left {
        *ret = append(*ret, append(append([]int{}, cur...), root.Val))
        return
    }else {
        if root.Left != nil {
            recur(ret, left - root.Val, append(cur, root.Val), root.Left)
        }
        if root.Right != nil {
            recur(ret, left - root.Val, append(cur, root.Val), root.Right)
        }
    }
}
