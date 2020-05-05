/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    ret := math.MinInt32
    dfs(root, &ret)
    return ret
}

func dfs(root *TreeNode, ret *int) int {
    if root == nil {
        return 0
    }
    if root.Val > *ret {
        *ret = root.Val
    }
    left := dfs(root.Left, ret)
    if left < 0 {
        left = 0
    }
    right := dfs(root.Right, ret)
    if right < 0 {
        right = 0
    }
    if left + right + root.Val > *ret {
        *ret = left + right + root.Val
    }
    if left > right {
        return left + root.Val
    }else {
        return right + root.Val
    }
}
