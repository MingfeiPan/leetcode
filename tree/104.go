/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var ret int
    MaxD(&ret, root, 0)
    return ret
}

func MaxD(ret *int, root *TreeNode, cur int) {
    if root.Left == nil && root.Right == nil {
        if cur + 1 > *ret {
            *ret = cur + 1
        }
    }
    if root.Left != nil {
        MaxD(ret, root.Left, cur+1)
    }
    if root.Right != nil {
        MaxD(ret, root.Right, cur+1)
    }
}
