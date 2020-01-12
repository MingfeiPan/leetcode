/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
    var ret int
    sum(root, &ret, false)
    return ret
}

func sum(root *TreeNode, ret *int, flag bool) {
    if root == nil {
        return 
    }
    if root.Left == nil && root.Right == nil && flag{
        *ret += root.Val
    }
    if root.Left != nil {
        sum(root.Left, ret, true)
    }
    if root.Right != nil {
        sum(root.Right, ret, false)
    }
}
