/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    if root == nil {
        return true
    }
    var leftH, rightH int
    height(root.Left, 0, &leftH)
    height(root.Right, 0, &rightH)
    if abs(leftH, rightH) > 1 {
        return false
    }else {
        return isBalanced(root.Left) && isBalanced(root.Right)
    }
}

func abs(a int, b int) int {
    if a < b {
        return b - a 
    }else {
        return a - b
    }
}

func height(root *TreeNode, cur int, ret *int) {
    if root == nil {
        return
    }
    if root.Left == nil && root.Right == nil {
        if cur+1 > *ret {
            *ret = cur+1
        }
        return
    }
    if root.Left != nil {
        height(root.Left, cur+1, ret)
    }
    if root.Right != nil {
        height(root.Right, cur+1, ret)
    }
}
